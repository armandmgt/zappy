import json

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
		try:
			_, arg = message.split(maxsplit=1)
			self.parse_information(arg)
		except ValueError:
			print(f'Invalid message received: {message}')

	def parse_information(self, arg: str):
		cell_num, arg = arg.split(', ', maxsplit=1)
		team_name, level, inventory_str = arg.split(';')
		inventory = json.loads(inventory_str)
		if team_name != self.client.team:
			return
		print(inventory)
