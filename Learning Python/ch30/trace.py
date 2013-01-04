class wrapper:
	def __init__(self, object):
		self.wrapped = object
	def __getattr__(self,attrname):
		print "Trace:", attrname
		return getattr(self.wrapped, attrname)
