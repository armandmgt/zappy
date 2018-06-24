<<<<<<< HEAD
from common.vec import Vec2d
=======
>>>>>>> dd6cd9d5a500eeb743b9d1916a6b70b2f51b8c85
from classes.inventory import Inventory
from common.vec import Vec2d


class Player:
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
<<<<<<< HEAD
=======

	def to_str(self) -> str:
		return f'{self.level};{self.inventory}'
>>>>>>> dd6cd9d5a500eeb743b9d1916a6b70b2f51b8c85
