class MyList:
    def __init__(self, wrapped=[]):
        self.next = 0
        self.wrapped = wrapped[:]

    def __add__(self, other):
        return MyList(self.wrapped + other)

    def __getitem__(self, index):
        return self.wrapped[index]

    def __iter__(self):
        return self

    def __mul__(self, other):
        return self.wrapped * other

    def __getslice__(self, low, high, step=None):
        self.wrapped[low:high:step]

    def __setslice__(self, low, high, step, value):
        self.wrapped[low:high:step] = value

    def __next__(self):
        if self.next <= len(self.wrapped):
            self.next = self.next + 1
            return self.wrapped[next]
        else:
            raise StopIteration

    def __append__(self, other):
        self.wrapped.apped(other)

    def __sort__(self):
        self.wrapped.sort()

    def __getattr__(self, attr):
        return getattr(self.wrapped, attr)
