
def find(iterable: list, key=lambda x: x):
	for elem in iterable:
		if key(elem):
			return elem
	return None
