from classes.inventory import Inventory
from common.vec import Vec2d


class Player:
	id = -1
	level = 1
	position: Vec2d = Vec2d(0, 0)
	timeout: int = 0
	orientation = 0
	inventory = Inventory()
	vision = []

	def __init__(self, pid: int, pos: Vec2d or None):
		self.id = pid
		self.position = pos if not None else Vec2d(0, 0)
		for x in range(4):
			self.vision.append(Inventory())

	def to_str(self) -> str:
		return f'{self.level};{self.inventory}'
