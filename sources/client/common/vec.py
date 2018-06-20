class Vec2d:
	__x = None
	__y = None

	def __init__(self, x, y):
		if type(x) is not type(y):
			raise RuntimeError("A vector must have both elements of the same type")
		self.__x = x
		self.__y = y

	def first(self):
		return self.__x

	def second(self):
		return self.__y
