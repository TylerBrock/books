def adder(*args):
    sum = args[0]
    for arg in args[1:]:
        sum += arg
    return sum

print "Two strings:"
print adder("test","concat")
print "Two lists:"
print adder([1],["testlist"])
print "Two floats:"
print adder(1.23,5.23)

def adderk(**args):
    return adder(*args.values())
