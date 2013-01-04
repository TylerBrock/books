class Adder:
	def __init__(self, start = []):
		self.data = start
	def __add__(self, other):
		return self.add(other)
	def add(self, y):
		print "Not implemented"

class ListAdder(Adder):
	def add(self, y):
		return self.data + y

class DictAdder(Adder):
	def add(self, y):
		for k in y.keys(): self.data[k] = y[k]
		return self.data
