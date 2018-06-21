import socket
from common.vec import Vec2d
from classes.player import Player

_max_buffer_size = 4096


def parse_response_array(s: str) -> []:
	translator = str.maketrans('', '', '[]\n')
	data = s.translate(translator).strip().split(',')
	return data


class Client:
	player: Player = None
	sock = socket.socket()
	port = -1
	team = ''
	mapSize = Vec2d(0, 0)
	host: str
	slotsLeft: int

	def __init__(self, port: int, name: str, host: str):
		self.host = host
		self.port = port
		self.team = name

		self.player = Player(pid=0, pos=Vec2d(0, 0))

	def connect(self):
		self.sock.connect((self.host, self.port))

	def read(self) -> str:
		return self.sock.recv(_max_buffer_size).decode()

	def write(self, data):
		if not data.endswith('\n'):
			data += '\n'
		self.sock.send(data.encode())

	def terminate(self):
		self.sock.close()

	def get_initial_data(self, data: str):
		datalist = data.split('\n')
		self.slotsLeft = int(datalist[0])
		s = datalist[1].split(' ')
		self.mapSize = Vec2d(int(s[0]), int(s[1]))

	def move_forward(self):
		self.write('Forward')
		if self.player.orientation == 0:  # NORTH
			self.player.position.set_y((self.player.position.second() + 1) % self.mapSize.second())
		elif self.player.orientation == 1:  # SOUTH
			self.player.position.set_y((self.player.position.second() - self.mapSize.second() + 1) % self.mapSize.second())
		elif self.player.orientation == 2:  # EAST
			self.player.position.set_x((self.player.position.first() + 1) % self.mapSize.first())
		elif self.player.orientation == 3:  # WEST
			self.player.position.set_x((self.player.position.first() - self.mapSize.second() + 1) % self.mapSize.first())

	def turn_right(self):
		self.write('Right')
		self.player.orientation = (self.player.orientation + 1) % 4

	def turn_left(self):
		self.write('Left')
		self.player.orientation = (self.player.orientation - 1) % 4

	def look(self):
		self.write('Look')
		data = parse_response_array(self.read())
		for s, vision in zip(data, self.player.vision):
			segment = s.strip().split(' ')
			for key in segment:
				vision[key] += 1

	def get_inventory(self):
		self.write('Inventory')
		data = parse_response_array(self.read())

		for s in data:
			item, val = s.strip().split(' ')
			self.player.inventory[item] = val

	def broadcast(self, text: str):
		self.write('Broadcast ' + text)

	def get_remaining_slots(self):
		self.write('Connect_nbr')
		self.slotsLeft = int(self.read())

	def fork(self):
		if self.slotsLeft > 0:
			self.write('Fork')

	def eject(self):
		self.write('Eject')

	def take(self, item: str):
		self.write('Take ' + item)
		if self.read().strip() == 'ok':
			self.player.inventory[item] += 1

	def set(self, item: str):
		if self.player.inventory[item] <= 0:
			return
		self.write('Set ' + item)
		if self.read().strip() == 'ok':
			self.player.inventory[item] -= 1
			self.player.vision[0][item] += 1

	def incantation(self):
		if self.player.busy:
			return
		self.write('Incantation')
		self.player.busy = True
		response = self.read().strip()
		if response == 'ko':
			self.player.busy = False
			return
		el, lvl = response.split('\n')
		new_lvl = lvl.split(' ')
		self.player.level = int(new_lvl[len(new_lvl) - 1])
		self.player.busy = False