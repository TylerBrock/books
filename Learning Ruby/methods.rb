def take_block(p1)
	if block_given?
		yield(p1)
	else
		p1
	end
end

p take_block("No block")
p take_block("no block") {|s| s.sub(/no /, '') }

class TaxCalculator
	def initialize(name, &block)
		@name, @block = name, block
	end
	def get_tax(amount)
		"#@name on #{amount} = #{@block.call(amount)}"
	end
end

tc = TaxCalculator.new("Sales tax") {|amt| amt * 0.075}

p tc.get_tax(100)
p tc.get_tax(250)

def meth_three
	100.times do |num|
		square = num*num
		return num, square if square > 1000
	end
end

num, square = meth_three
p num, square

print "(t)imes or (p)lus: "
times = gets
print "number: "
number = Integer(gets)

if times =~ /^t/
	puts((1..10).collect {|n| n*number }.join(", "))
else
	puts((1..10).collect {|n| n+number }.join(", "))
end
