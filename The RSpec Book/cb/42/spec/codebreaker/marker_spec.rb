require 'spec_helper'

module Codebreaker
  describe Marker do
    describe "#exact_match_count" do
      context "with no matches" do
        it "returns 0" do
          marker = Marker.new('1234', '5555')
          marker.exact_match_count.should == 0
        end
      end

      
    end
  end
end