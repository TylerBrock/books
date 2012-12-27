class Bicycle
  attr_reader :size, :chain, :tire_size
  def initialize(args={})
    @size      = args[:size]
    @chain     = args[:chain]     || default_chain
    @tire_size = args[:tire_size] || default_tire_size
  end

  def default_chain
    '10-speed'
  end
end

class RoadBike < Bicycle
  attr_reader :tape_color

  def initialize(args)
    @tape_color = args[:tape_color]
    super(args)
  end

  def default_tire_size
    '23'
  end

  def spares
    {
      :chain      => '10 speed',
      :tire_size  => '23',
      :tape_color => tape_color
    }
  end
end

class MountainBike < Bicycle
  attr_reader :front_shock, :rear_shock

  def initialize(args)
    @front_shock = args[:front_shock]
    @rear_shock  = args[:rear_shock]
    super(args)
  end

  def default_tire_size
    '2.1'
  end

  def spares
    super.merge(:rear_shock => rear_shock)
  end
end

road_bike = RoadBike.new(
  :size       => 'M',
  :tape_color => 'red'
)
puts road_bike.tire_size
puts road_bike.chain

mountain_bike = MountainBike.new(
  :size        => 'S',
  :front_shock => 'Manitou',
  :rear_shock  => 'Fox'
)
puts mountain_bike.tire_size
puts mountain_bike.chain