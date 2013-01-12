module Codebreaker
  class Game
    def initialize(output)
      @output = output
    end

    def start(secret)
      @secret = secret
      @output.puts 'Welcome to Codebreaker!'
      @output.puts 'Enter guess:'
    end

    def guess(guess)
      if @secret.include?(guess[0])
        @output.puts '-'
      else
        @output.puts ''
      end
    end
  end
end