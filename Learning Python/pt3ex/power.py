L = [1, 2, 4, 8, 16, 32, 64]
X = 5

# Version 1
found = False
i = 0
while not found and i < len(L):
    if 2 ** X == L[i]:
        found = True
    else:
        i = i+1

if found:
    print 'at index', i
else:
    print X, 'not found'

# Version 2 (part a)

while i < len(L):
    if 2 ** X == L[i]:
        print 'at index', i
        break
    i += 1
else:
    print X, 'not found'

# Version 3 (part b)
for i in L:
    if (2 ** X) == i:
        print (2 ** X), 'at index', L.index(i)
        break
    i += 1
else:
    print X, 'not found'

# Version 4 (part c)
if (2 ** X) in L:
    print (2 ** X), 'at index', L.index(2 ** X)
else:
    print X, 'not found'

# Version 5 (part d)
print 'this is L:', L
L = []
print 'this is L cleared:', L
for i in range(7):
    L.append(2 ** i)
print L

# Version 6 (part f)
print map(lambda x: 2 ** x, range(7))
