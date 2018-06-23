from classes.client import Client


class AI:
	client: Client
	priority_list = []

	def __init__(self, c: Client):
		self.client = c

	def make_decision(self, message: str):
		if not message:
			self.client.send_information()
			return
		print(f'make decision with {message}')
		command, *arg = message.split(maxsplit=1)
		arg = arg[0] if arg else ''
		print(f'command [{command}] arg [{arg}]')
		self.parse_information()

	def parse_information(self):
		pass
