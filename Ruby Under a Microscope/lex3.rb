require 'ripper'
require 'pp'

code = <<STR
array = []
10.times do |n|
  array << n if n < 5
end
p array
STR

puts code
pp Ripper.lex(code)
