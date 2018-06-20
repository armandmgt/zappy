import socket

_max_buffer_size = 4096


class Client:
	sock = socket.socket()
	port = -1
	teamName = ""
	host = ""

	def __init__(self, port: int, name: str, host: str):
		self.host = host
		self.port = port
		self.teamName = name

	def connect(self):
		self.sock.connect((self.host, self.port))

	def read(self):
		return self.sock.recv(_max_buffer_size)

	def write(self, data):
		self.sock.send(data)

	def terminate(self):
		self.sock.close()

# 	debug methods
	def dump(self):
		print('port:\t', self.port)
		print('team:\t', self.teamName)
		print('host:\t', self.host)
