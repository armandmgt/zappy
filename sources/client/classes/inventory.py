_ITEMS = [
	'food',
	'sibur',
	'phiras',
	'mendiane',
	'thystame',
	'linemate',
	'deraumere',
	'player'
]


class Inventory(dict):
	def __init__(self):
		super().__init__()
		for k in _ITEMS:
			self.__setitem__(k, 0)
		self['food'] = 10

	def __setitem__(self, k, v):
		super(Inventory, self).__setitem__(k, v)

	def __getitem__(self, k):
		return super(Inventory, self).__getitem__(k)

	def __repr__(self):
		return super(Inventory, self).__repr__()

	def __len__(self):
		return super(Inventory, self).__len__()

	def __delitem__(self, k):
		return super(Inventory, self).__delitem__(k)

	def clear(self):
		return super(Inventory, self).clear()

	def copy(self):
		return super(Inventory, self).copy()

	def has_k(self, k):
		return k in super().__dict__

	def update(self, *args, **kwargs):
		return super(Inventory, self).update(*args, **kwargs)

	def keys(self):
		return super(Inventory, self).keys()

	def values(self):
		return super(Inventory, self).values()

	def items(self):
		return super(Inventory, self).items()
