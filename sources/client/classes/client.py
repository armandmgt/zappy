import socket
from common.vec import Vec2d

_max_buffer_size = 4096


class Client:
	player = None
	sock = socket.socket()
	port = -1
	team = ""
	mapSize = Vec2d(0, 0)
	host: str
	slotsLeft: int

	def __init__(self, port: int, name: str, host: str):
		self.host = host
		self.port = port
		self.team = name

	def connect(self):
		self.sock.connect((self.host, self.port))

	def read(self) -> str:
		return self.sock.recv(_max_buffer_size).decode()

	def write(self, data):
		data += '\n'
		self.sock.send(data.encode())

	def terminate(self):
		self.sock.close()

	def get_initial_data(self, data: str):
		datalist = data.split("\n")
		self.slotsLeft = int(datalist[0])
		s = datalist[1].split(" ")
		self.mapSize = Vec2d(int(s[0]), int(s[1]))
