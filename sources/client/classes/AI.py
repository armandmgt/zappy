import json

from classes.client import Client
from classes.inventory import Inventory


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
			information = self.parse_information(arg)
		except ValueError:
			print(f'Invalid message received: {message}')

	def parse_information(self, arg: str):
		information = {'org': 0, 'lvl': 0, 'inv': Inventory()}
		information['org'], arg = arg.split(', ', maxsplit=1)
		team_name, information['lvl'], information['inv'] = arg.split(';')
		information['inv'] = json.loads(information['inv'])
		information['lvl'] = int(information['lvl'])
		if team_name != self.client.team:
			return
		return information
