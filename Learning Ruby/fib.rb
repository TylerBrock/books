def fib_up_to(max)
	i1, i2 = 1, 1
	while i1 <= max
		yield i1
		i1, i2 = i2, i1+i2
	end
end
fib_up_to(1000) {|f| print f, " "}

a = [1,2,3,4,5,6,7,8,9,10]

collection = a.collect { |num| num if num % 2 == 0}
print collection