from common.vec import Vec2d


class Player:
	id = -1
	level = 1
	position = None
	orientation = 0
	inventory = {"food": 0, "sibur": 0, "phiras": 0, "mendiane": 0, "thystame": 0, "linemate": 0, "deraumere": 0}
	vision = []

	def __init__(self, pid: int, pos: Vec2d or None):
		self.id = pid
		self.position = pos if not None else Vec2d(0, 0)
		for x in range(8):
			self.vision.append({"food": 0, "sibur": 0, "phiras": 0, "mendiane": 0, "thystame": 0, "linemate": 0, "deraumere": 0})
