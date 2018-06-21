class Vec2d:
	__x = None
	__y = None

	def __init__(self, x, y):
		if type(x) != type(y):
			raise RuntimeError("A vector must have both elements of the same type")
		self.__x = x
		self.__y = y

	def x(self):
		return self.__x

	def y(self):
		return self.__y

	def set_x(self, val):
		if not isinstance(val, type(self.__x)):
			return
		self.__x = val

	def set_y(self, val):
		if not isinstance(val, type(self.__y)):
			return
		self.__y = val
