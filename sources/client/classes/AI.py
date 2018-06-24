import json

from classes.client import Client
from classes.inventory import Inventory

_RESOURCES_NEEDED = [
	Inventory([0, 1, 0, 0, 0, 0, 0, 1]), Inventory([0, 1, 1, 1, 0, 0, 0, 2]),
	Inventory([0, 2, 0, 1, 0, 2, 0, 2]), Inventory([0, 1, 1, 2, 0, 1, 0, 4]),
	Inventory([0, 1, 2, 1, 3, 0, 0, 4]), Inventory([0, 1, 2, 3, 0, 1, 0, 6]),
	Inventory([0, 2, 2, 2, 2, 2, 1, 6])
]


class PlayerDesc:
	score: float
	origin: int
	level: int
	inventory: Inventory

	def __init__(self, score: float=0, origin: int=0, level: int=0, inventory: Inventory=Inventory()):
		self.score = score
		self.origin = origin
		self.level = level
		self.inventory = inventory


class AI:
	client: Client
	alpha_target: PlayerDesc

	def __init__(self, c: Client):
		self.client = c
		self.alpha_target = None

	def make_decision(self, message: str):
		if not message:
			self.client.send_information()
			return
		# try:
		_, arg = message.split(maxsplit=1)
		information = self.parse_information(arg)
		if information is None:
			return
		self.rank_information(information)
		# except ValueError:
		# 	print(f'Invalid message received: {message}')

	def parse_information(self, arg: str) -> PlayerDesc or None:
		information = PlayerDesc()
		information.origin, arg = arg.split(', ', maxsplit=1)
		team_name, information.level, information.inventory = arg.split(';')
		information.inventory = json.loads(information.inventory)
		information.level = int(information.level)
		if team_name != self.client.team:
			return None
		return information

	def rank_information(self, information: PlayerDesc):
		information.score += self.player_level_score(information.level) * 1
		information.score += self.resources_score(information.inventory) * 1
		information.score /= 2
		if self.alpha_target is None or self.alpha_target.score < information.score:
			self.alpha_target = information
			print('changed allegiance')

	def player_level_score(self, level: int) -> int:
		return 1 if self.client.player.level == level else 0

	def resources_score(self, inventory: Inventory) -> int:
		my_needed_resources = _RESOURCES_NEEDED[self.client.player.level - 1]
		my_needed_resources = Inventory([value - self.client.player.inventory[key] for (key, value) in my_needed_resources.items()])
		my_needed_resources = Inventory([0 if value < 0 else value for (_, value) in my_needed_resources.items()])
		resource_scores = []
		for (key, available) in inventory.items():
			missing_resource = my_needed_resources[key] - available
			if missing_resource < 0:
				missing_resource = 0
			resource_scores.append(missing_resource)
		return 1 / sum(resource_scores)
