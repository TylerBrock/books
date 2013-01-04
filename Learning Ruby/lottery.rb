class LotteryTicket

	NUMERIC_RANGE = 1..25

	attr_reader :picks, :purchased

	def initialize ( *picks )
		if picks.length != 3
			raise ArgumentError, "Three numbers must be picked"
		elsif picks.uniq.length != 3
			raise ArguementError, "The three picks must be different numbers"
		elsif picks.detect { |p| not NUMERIC_RANGE === p }
			raise ArguemtntError, "The three picks must be numbers between 1 and 25"
		end

		@picks = picks
		@purchased = Time.now
	end

end

class LotteryTicket
	def self.new_random
		new(
			rand( 25 ) + 1,
			rand( 25 ) + 1,
			rand( 25 ) + 1
		)
	rescue ArgumentError
		redo
	end
end

class LotteryDraw
	@@tickets = {}
	def LotteryDraw.buy( customer, *tickets )
		unless @@tickets.has_key?( customer )
			@@tickets[customer] = []
		end
		@@tickets[customer] += tickets
	end
end

LotteryDraw.buy 'Yal-dal-rip-sip',
	LotteryTicket.new( 12, 6, 19 ),
	LotteryTicket.new( 5, 1, 3 ),
	LotteryTicket.new( 24, 6, 8 )

class LotteryTicket
	def score( final )
	   	count = 0
     	final.picks.each do |note|
	     	count +=1 if picks.include? note
   		end
     	count
	end
end

ticket = LotteryTicket.new( 2, 5, 19 )
winner = LotteryTicket.new( 4, 5, 19 )
ticket.score( winner )

class << LotteryDraw
	def play
		final = LotteryTicket.new_random
		winners = {}
		@@tickets.each do |buyer, ticket_list|
			ticket_list.each do |ticket|
				score = ticket.score( final )
				next if score.zero?
				winners[buyer] ||= []
				winners[buyer] << [ticket, score]
			end
		end
		@@tickets.clear
		winners
	end
end