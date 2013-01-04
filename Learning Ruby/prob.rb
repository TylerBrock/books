#!/usr/bin/env ruby

count = Proc.new { [1,2,3,4,5].each do |i| print i end; puts }
your_proc = lambda { puts "Lurch: 'you rang?'" }
my_proc = proc { puts "Morticia: 'who was at the door, lurch?'" }

puts count.class, your_proc.class, my_proc.class

count.call
your_proc.call
my_proc.call