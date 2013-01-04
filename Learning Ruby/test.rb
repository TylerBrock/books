tyler = ['awesome', 'funny', 'cool']

tyler.each do |verb|
	puts verb	
end

class WishMaker
	def initialize
		@energy = rand( 6 )
	end

	def grant( wish )
		if wish.length > 10 or wish.include? ' '
			raise ArgumentError, "Bad Wish"
		end
		if energy.zero?
			raise Exception, "No energy left."
		end
		@energy -= 1
		Endertromb::make( wish )
	end
end
