from common.vec import Vec2d


class Player:
	id = -1
	team = None
	level = 1
	position = Vec2d(-1, -1)
	orientation = 0
	inventory = {"food": 0, "sibur": 0, "phiras": 0, "mendiane": 0, "thystame": 0, "linemate": 0, "deraumere": 0}
	vision = []
	for x in range(8):
		vision.append({"food": 0, "sibur": 0, "phiras": 0, "mendiane": 0, "thystame": 0, "linemate": 0, "deraumere": 0})

	def __init__(self, team: str, pos: Vec2d, no: int):
		self.team = team
		self.id = no
		self.position = pos
