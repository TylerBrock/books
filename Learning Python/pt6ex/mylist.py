class MyList:
	def __init__(self, start):
		self.wrapped = []
		for x in start: self.wrapped.append(x)
	def __add__(self, other):
		return MyList(self.wrapped + other)
	def __mul__(self, time):
		return MyList(self.wrapped * time)
	def __getitem__(self, offset):
		return self.wrapped[offset]
	def __len__(self):
		return len(self.wrapped)
	def __getslice__(self, low, high):
		return MyList(self.wrapped[low:high])
	def __getattr__(self, name):
		return getattr(self.wrapped, name)
	def __repr__(self):
		return repr(self.wrapped)
	def append(self, node):
		self.wrapped.append(node)

if __name__ == "__main__":
	x = MyList('spam')
	print x
	print x[2]
	print x[1:]
	print x + ['eggs']
	print x * 3
	x.append('a')
	x.sort()
	for c in x: print c,