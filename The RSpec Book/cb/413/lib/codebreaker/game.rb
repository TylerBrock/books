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
      marker = Marker.new(@secret, guess)
      @output.puts '+'*marker.exact_match_count(guess) +
                   '-'*marker.number_match_count(guess)
    end

    class Marker
      def initialize(secret, guess)
        @secret, @guess = secret, guess
      end

      def exact_match_count(guess)
        (0..3).inject(0) do |count, index|
          count + (exact_match?(@guess, index) ? 1 : 0)
        end
      end

      def number_match_count(guess)
        (0..3).inject(0) do |count, index|
          count + (number_match?(@guess, index) ? 1 : 0)
        end
      end

      def exact_match?(guess, index)
        @guess[index] == @secret[index]
      end

      def number_match?(guess, index)
        @secret.include?(@guess[index]) && !exact_match?(@guess, index)
      end
    end
  end
end