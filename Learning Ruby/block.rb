def call_block
	puts "Start of method"
	yield("Ashole1")
	yield("Ashole2")
	puts "End of method"
end

call_block { |word| puts "In the block #{word}" }