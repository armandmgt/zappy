from collections import KeysView


def find(iterable: list or KeysView, key=lambda x: x):
	for elem in iterable:
		if key(elem):
			return elem
	return None


def index(iterable: list, key=lambda x: x) -> int:
	x = 0
	for elem in iterable:
		if key(elem):
			return x
		x += 1
	return -1
