from lister import *

class Super:
	def __init__(self):
		self.data1 = 'spam'
	def ham(self):
		pass
		
class Sub(Super, ListInstance):
	def __init__(self):
		Super.__init__(self)
		self.data2 = 'eggs'
		self.data3 = 42
	def spam(self):
		pass
		
class Sub2(Super, ListInherited):
	def __init__(self):
		Super.__init__(self)
		self.data2 = 'eggs'
		self.data3 = 42
	def spam(self):
		pass
		
class Sub3(Super, ListTree):
	def __init__(self):
		Super.__init__(self)
		self.data2 = 'eggs'
		self.data3 = 42
	def spam(self):
		pass
		
if __name__ == "__main__":
	X = Sub()
	Y = Sub2()
	Z = Sub3()
	print X
	print Y
	print Z