from classes.client import Client


class AI:
	client: Client
	priority_list = []

	def __init__(self, c: Client):
		self.client = c

	def make_decision(self, response: str):
		if not response:
			self.client.send_information()
			return
		print(f'make decision with {response}')
		command, *arg = response.split(maxsplit=1)
		arg = arg[0] if arg else ''
		print(f'command [{command}] arg [{arg}]')
		self.parse_information()

	def parse_information(self):
		pass
