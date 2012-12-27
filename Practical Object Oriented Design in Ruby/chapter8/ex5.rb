require 'forwardable'

class Bicycle
  attr_reader :size, :parts

  def initialize(args={})
    @size  = args[:size]
    @parts = args[:parts]
  end

  def spares
    parts.spares
  end
end

class Parts
  extend Forwardable
  def_delegators :@parts, :size, :each
  include Enumerable

  def initialize(parts)
    @parts = parts
  end

  def spares
    select {|part| part.needs_spare}
  end
end

class Part
  attr_reader :name, :description, :needs_spare

  def initialize(args)
    @name        = args[:name]
    @description = args[:description]
    @needs_spare = args.fetch(:needs_spare, true)
  end
end

chain         = Part.new(:name => 'chain', :description => '10-speed')
road_tire     = Part.new(:name => 'tire_size', :description => '23')
tape          = Part.new(:name => 'tape_color', :description => 'red')
mountain_tire = Part.new(:name => 'tire_size', :description => '2.1')
rear_shock    = Part.new(:name => 'rear_shock', :description => 'Fox')
front_shock   = Part.new(:name => 'front_shock', :description => 'Manitou', :needs_spare => false)

mountain_bike_parts = Parts.new([chain, mountain_tire, front_shock, rear_shock])

mountain_bike = Bicycle.new(
  :size  => 'L',
  :parts => mountain_bike_parts
)

puts mountain_bike.spares.size
puts mountain_bike.parts.size