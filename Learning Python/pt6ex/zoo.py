class Animal:
	def reply(self):: self.speak()
	def speak(self): print 'spam'

class Mammal(Animal):
	def speak(self): print 'huh?'
	
class Cat(Animal):
	def speak(self): print 'meow'
	
class Dog(Animal):
	def speak(self): print 'bark'
	
class Primate(Animal):
	def speak(self): print 'hello world!'
	
class Hacker(Primate): pass