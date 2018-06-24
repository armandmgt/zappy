import json
from random import randint

from numpy.core.umath import sign

from classes.client import Client
from classes.inventory import Inventory
from common.listtools import find
from common.vec import Vec2d

_RESOURCES_NEEDED = [
	Inventory([0, 1, 0, 0, 0, 0, 0, 1]),
	Inventory([0, 1, 1, 1, 0, 0, 0, 2]),
	Inventory([0, 2, 0, 1, 0, 2, 0, 2]),
	Inventory([0, 1, 1, 2, 0, 1, 0, 4]),
	Inventory([0, 1, 2, 1, 3, 0, 0, 4]),
	Inventory([0, 1, 2, 3, 0, 1, 0, 6]),
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
		if message:
			try:
				_, arg = message.split(maxsplit=1)
				information = self.parse_information(arg)
				if information is None:
					return
				self.rank_information(information)
			except ValueError:
				print(f'Invalid message received: {message}')

		self.client.get_inventory()
		if self.client.player.inventory['food'] < 5:
			self.go_for_food()
		else:
			self.go_for_target()

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
		my_needed_resources = _RESOURCES_NEEDED[
			self.client.player.level - 1]
		for (key, value) in my_needed_resources.items():
			new_value = value - self.client.player.inventory[key]
			my_needed_resources[key] = 0 if new_value < 0 else new_value
		resource_scores = []
		for (key, available) in inventory.items():
			missing_resource = my_needed_resources[key] - available
			if missing_resource < 0:
				missing_resource = 0
			resource_scores.append(missing_resource)
		return 1 / sum(resource_scores)

	def go_for_food(self):
		found = find(self.client.player.vision, key=lambda x: x == 'food')
		pos: Vec2d
		if found is not None:
			index = self.client.player.vision.index(found)
			pos = Vec2d(index / self.client.mapSize.x, index % self.client.mapSize.x)
		else:
			pos = Vec2d(randint(0, self.client.mapSize.x), randint(0, self.client.mapSize.y))
		print(self.best_direction(pos))

	def go_for_target(self):
		pass

	def best_direction(self, pos: Vec2d):
		deltax = pos.x() - self.client.player.position.x()
		deltay = pos.y() - self.client.player.position.y()
		if abs(deltax) > abs(deltay):
			direction = 3 + sign(deltax)
		else:
			direction = 2 + sign(deltay)
		l_turns = (self.client.player.orientation - direction + 4) % 4
		r_turns = (direction - self.client.player.orientation + 4) % 4
		turns = min((l_turns, 'Left'), (r_turns, 'Right'), key=lambda x: x[0])
		if turns[0] == 0:
			return 'Forward'
		return turns[1]
