S = 'spam'
for char in S:
    print char,'->',ord(char)

total = 0
for char in S: total += ord(char)
print total

sum([ord(x) for x in S])

[ord(x) for x in S]

list = []
for char in S:
    list.append(ord(char))
print list

print map(ord,S)

