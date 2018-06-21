from common.vec import Vec2d


class Player:
	id = -1
	level = 1
	position: Vec2d = Vec2d(0, 0)
	timeout: int = 0
	orientation = 0
	inventory = dict(food=10, sibur=0, phiras=0, mendiane=0, thystame=0, linemate=0, deraumere=0, player=0)
	vision = []

	def __init__(self, pid: int, pos: Vec2d or None):
		self.id = pid
		self.position = pos if not None else Vec2d(0, 0)
		for x in range(4):
			self.vision.append(dict(food=0, sibur=0, phiras=0, mendiane=0, thystame=0, linemate=0, deraumere=0, player=0))
