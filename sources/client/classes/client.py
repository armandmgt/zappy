import socket
from multiprocessing import Queue
from threading import Thread

from classes.player import Player
from common.vec import Vec2d

_max_buffer_size = 4096


# TODO: Needs documentation
def parse_response_array(s: str) -> []:
	translator = str.maketrans('', '', '[]')
	data = s.translate(translator).split(',')
	return data


def clamp(value, max_val):
	assert type(value) == type(max_val)
	return value + max_val % max_val


class Client:
	player: Player = None
	sock = socket.socket()
	port = -1
	team = ''
	mapSize = Vec2d(0, 0)
	host: str
	slotsLeft: int
	responses = Queue()

	def __init__(self, port: int, name: str, host: str):
		self.r_th = Thread(target=self.read, args=(self.sock, self.responses))
		self.host = host
		self.port = port
		self.team = name

		self.player = Player(pid=0, pos=Vec2d(0, 0))

	def connect(self):
		self.sock.connect((self.host, self.port))
		self.r_th.daemon = True
		self.r_th.start()

	@staticmethod
	def read(sock: socket, responses: Queue):
		buf = ''
		while True:
			buf += sock.recv(_max_buffer_size).decode()
			if len(buf) == 0:
				return
			while buf.find('\n') is not -1:
				res, *buf = buf.split('\n')
				buf = '\n'.join(buf)
				responses.put(res)

	def write(self, data):
		if not data.endswith('\n'):
			data += '\n'
		self.sock.send(data.encode())

	def terminate(self):
		self.sock.close()

	def get_initial_data(self):
		self.slotsLeft = int(self.responses.get())
		x, y = self.responses.get().split(' ')
		self.mapSize = Vec2d(int(x), int(y))

	def move_forward(self):
		self.write('Forward')
		if self.player.orientation == 0:  # NORTH
			self.player.position.set_y(clamp(self.player.position.y() + 1, self.mapSize.y()))
		elif self.player.orientation == 1:  # SOUTH
			self.player.position.set_y(clamp(self.player.position.y() - 1, self.mapSize.y()))
		elif self.player.orientation == 2:  # EAST
			self.player.position.set_x(clamp(self.player.position.x() + 1, self.mapSize.x()))
		elif self.player.orientation == 3:  # WEST
			self.player.position.set_x(clamp(self.player.position.x() - 1, self.mapSize.x()))

	def turn_right(self):
		self.write('Right')
		self.player.orientation = (self.player.orientation + 1) % 4

	def turn_left(self):
		self.write('Left')
		self.player.orientation = (self.player.orientation - 1) % 4

	def look(self):
		self.write('Look')
		data = parse_response_array(self.responses.get())
		for s, vision in zip(data, self.player.vision):
			segment = s.strip().split(' ')
			for key in segment:
				vision[key] += 1

	def get_inventory(self):
		self.write('Inventory')
		data = parse_response_array(self.responses.get())

		for s in data:
			item, val = s.strip().split(' ')
			self.player.inventory[item] = val

	def send_information(self):
		text = f'{self.team};{self.player.to_str()}'
		self.broadcast(text)

	def broadcast(self, text: str):
		self.write('Broadcast ' + text)

	def get_remaining_slots(self):
		self.write('Connect_nbr')
		self.slotsLeft = int(self.responses.get())

	def fork(self):
		if self.slotsLeft > 0:
			self.write('Fork')

	def eject(self):
		self.write('Eject')

	def take(self, item: str):
		self.write('Take ' + item)
		if self.responses.get() == 'ok':
			self.player.inventory[item] += 1

	def set(self, item: str):
		if self.player.inventory[item] <= 0:
			return
		self.write('Set ' + item)
		if self.responses.get().strip() == 'ok':
			self.player.inventory[item] -= 1
			self.player.vision[0][item] += 1

	def incantation(self):
		if self.player.timeout is not 0:
			return
		self.write('Incantation')
		response = self.responses.get()
		if response == 'ko':
			return
		self.player.timeout = 300
