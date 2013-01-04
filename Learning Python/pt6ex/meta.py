class Meta:
	def __getattr__(self, name):
		print "get", name
	def __setattr__(self, name, value):
		print "set", name, value