import socket
from common.vec import Vec2d
from classes.player import Player

_max_buffer_size = 4096


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
			self.player.position.set_x((self.player.position.first() + 1) % self.mapSize.first())
		elif self.player.orientation == 1:  # SOUTH
			self.player.position.set_x((self.player.position.first() - self.mapSize.first()) % self.mapSize.first())
		elif self.player.orientation == 2:  # EAST
			self.player.position.set_y((self.player.position.second() + 1) % self.mapSize.second())
		elif self.player.orientation == 3:  # WEST
			self.player.position.set_y((self.player.position.second() - self.mapSize.second()) % self.mapSize.second())

	def turn_right(self):
		self.write('Right')
		self.player.orientation = (self.player.orientation + 1) % 4

	def turn_left(self):
		self.write('Left')
		self.player.orientation = (self.player.orientation - 1) % 4

	def look(self):
		self.write('Look')
		response = self.read()
		translator = str.maketrans('', '', '[]\n')
		data = response.translate(translator).strip().split(',')
		i = 0

		for s in data:
			segment = s.strip().split(' ')
			for key in segment:
				self.player.vision[i][key] += 1
			i += 1
