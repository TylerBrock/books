import math
squares = [2, 4, 9, 16, 25]

res = []
for square in squares:
    res.append(math.sqrt(square))
print res

res = map(math.sqrt, squares)
print res

res = [math.sqrt(square) for square in squares]
print res
