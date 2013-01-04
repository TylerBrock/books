class Lunch:
	"""
	A container and controller class
	"""
	def __init__(self):
		self.customer = Customer()
		self.employee = Employee()
	def order(self, foodName):
		self.customer.placeOrder(foodName, self.employee)
	def result(self):
		self.customer.printFood()
	
class Customer:
	"""
	The actor who buys the food
	"""
	def __init__(self):
		self.food = None
	def placeOrder(self, foodName, employee):
		self.food = employee.takeOrder(foodName)
	def printFood(self):
		print self.food.name
	
class Employee:
	"""
	The actor from whom a customer orders
	"""
	def takeOrder(self, foodName):
		return Food(foodName)
	
class Food:
	"""
	What the customer buys
	"""
	def __init__(self, name):
		self.name = name
		
if __name__ == '__main__':
	x = Lunch()
	x.order('burritos')
	x.result()
	x.order('pizza')
	x.result()
