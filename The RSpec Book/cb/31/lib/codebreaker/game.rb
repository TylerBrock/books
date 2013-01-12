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
      if guess[0] == @secret[0]
        mark = '+'
      elsif @secret.include?(guess[0])
        mark = '-'
      else
        mark = ''
      end
      @output.puts mark
    end
  end
end