class Accounts
	def initialize(checking, savings)
		@checking = checking
		@savings = savings
	end
	private
		def debit(account, amount)
			account.balance -= amount
		end
		def credit(account, amount)
			account.balance += amount
		end
	public
		def transfer_to_savings(amount)
			debit(@checking, amount)
			credit(@savings, amount)
		end
end

class Account
	attr_reader :balance
	protected :balance
	def greater_balance_than(other)
		return @balance > other.balance
	end
end
