class ListInstance:
		"""
		Mix-in class that provides a formatted print() or str() of
		instances via inheritance of __str__, coded here; displays
		instance attrs only; self is the instance of lowest class;
		uses __X names to avoid clashing with client's atts
		"""
		def __str__(self):
			return "<Instance of %s, address %s:\n%s>" % (
									self.__class__.__name__,
									id(self),
									self.__attrnames())

		def __attrnames(self):
			result = ''
			for attr in sorted(self.__dict__):
				result += '\tname %s=%s\n' % (attr, self.__dict__[attr])
			return result
			
		def __supers(self):
			names = []
			for super in self.__class__.__bases__:
				names.append(super.__name__)
			return ", ".join(names)
			
class ListInherited:
		"""
		Use dir() to collect both instance attrs and names
		inherited from its classes; Python 3.0 shows more
		names than 2.6 because of the implied object superclass
		in the new-style class model; getattr() fetches inherited
		names not in the self.__dict__; use __str__, not __repr__,
		or else this loops when printing bound methods!
		"""
		def __str__(self):
			return "<Instance of %s(%s), address %s:\n%s>" % (
				self.__class__.__name__,
				id(self),
				self.__attrnames())

		def __attrnames(self):
			result = ''
			for attr in dir(self):
				if attr[:2] == '__' and attr[-2:] == '__':
					result += '\tname %s=<>\n' % attr
				else:
					result += '\tname %s=%s\n' % (attr, getattr(self, attr))
			return result
			
class ListTree:
		"""
		Mix-in that returns an __str__ trace of the entire class
		tree and all its objects' attrs at and above self;
		run by print(), str() reuturns constructed string;
		uses __X attr names to avoid impacting clients;
		uses generator expr to recurs to superclasses;
		uses str.format() to make subsitutions clearer
		"""
		def __str__(self):
			self.__visited = {}
			return "<Instance of {0}, address {1}:\n{2}{3}>".format(
									self.__class__.__name__,
									id(self),
									self.__attrnames(self, 0),
									self.__listclass(self.__class__, 4))
		def __listclass(self, aClass, indent):
			dots = '.' * indent
			if aClass in self.__visited:
				return '\n{0}<Class {1}:, address {2}: (see above)>\n'.format(
					dots,
					aClass.__name__,
					id(aClass))
			else:
				self.__visited[aClass] = True
				genabove = (self.__listclass(c, indent+4) for c in aClass.__bases__)
				return "\n{0}<Class {1}, address {2}:\n{3}{4}{5}>\n".format(
					dots,
					aClass.__name__,
					id(aClass),
					self.__attrnames(aClass, indent),
					''.join(genabove),
					dots)
					
		def __attrnames(self, obj, indent):
			spaces = ' ' * (indent + 4)
			result = ''
			for attr in sorted(obj.__dict__):
				if attr.startswith('__') and attr.endswith('__'):
					result += spaces + '{0}=<>\n'.format(attr)
				else:
					result += spaces + '{0}={1}\n'.format(attr, getattr(obj, attr))
			return result