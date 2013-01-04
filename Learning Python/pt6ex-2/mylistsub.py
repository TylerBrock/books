from mylist import MyList

class MyListSub(MyList):
    count = 0
    def __getattr__(self):
        print "Overload"
