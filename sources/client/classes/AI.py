import json

from classes.client import Client
from classes.inventory import Inventory

_RESOURCES_NEEDED = [
	Inventory([0, 1, 0, 0, 0, 0, 0, 1]), Inventory([0, 1, 1, 1, 0, 0, 0, 2]),
	Inventory([0, 2, 0, 1, 0, 2, 0, 2]), Inventory([0, 1, 1, 2, 0, 1, 0, 4]),
	Inventory([0, 1, 2, 1, 3, 0, 0, 4]), Inventory([0, 1, 2, 3, 0, 1, 0, 6]),
	Inventory([0, 2, 2, 2, 2, 2, 1, 6])
]


class AI:
	client: Client
	priority_list = []

	def __init__(self, c: Client):
		self.client = c

	def make_decision(self, message: str):
		if not message:
			self.client.send_information()
			return
		# try:
		_, arg = message.split(maxsplit=1)
		information = self.parse_information(arg)
		self.rank_information(information)
		# except ValueError:
		# 	print(f'Invalid message received: {message}')

	def parse_information(self, arg: str):
		information = {'org': 0, 'lvl': 0, 'inv': Inventory()}
		information['org'], arg = arg.split(', ', maxsplit=1)
		team_name, information['lvl'], information['inv'] = arg.split(';')
		information['inv'] = json.loads(information['inv'])
		information['lvl'] = int(information['lvl'])
		if team_name != self.client.team:
			return
		return information

	def rank_information(self, information: dict):
		score = 0
		score += self.player_level_score(information['lvl']) * 1
		score += self.resources_score(information['inv']) * 1
		score /= 2
		self.priority_list.append((score, {
			'org': information['org'],
			'dir': self.client.player.orientation
		}))

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

	def player_level_score(self, level: int) -> int:
		return 1 if self.client.player.level == level else 0
