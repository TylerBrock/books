num = 81
6.times do
	puts "#{num.class}: #{num}"
	num *= num
end

p Fixnum.instance_methods

a = Integer(123012730127093812903)
p a.class

