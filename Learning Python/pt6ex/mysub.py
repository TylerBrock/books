from mylist import MyList

class MyListSub(MyList):
	calls = 0
	def __init__(self, start):
		self.adds = 0
		MyList.__init__(self,start)
	def __add__(self, other):
		MyListSub.calls += 1
		self.adds += 1
		return MyList.__add__(self,other)
	def stats(self):
		return self.calls, self.adds

if __name__ == "__main__":
	x = MyListSub('spam')
	y = MyListSub('foo')
	print x[2]
	print x[1:]
	print x + ['eggs']
	print x + ['toast']
	print y + ['bar']
	print x.stats()