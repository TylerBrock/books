require 'minitest/autorun'

class Bicycle
  attr_reader :size, :chain, :tire_size
  def initialize(args={})
    @size      = args[:size]
    @chain     = args[:chain]     || default_chain
    @tire_size = args[:tire_size] || default_tire_size

    post_initialize(args)
  end

  def post_initialize(args)
    nil
  end

  def spares
    {
      :tire_size => tire_size,
      :chain     => chain
    }.merge(local_spares)
  end

  def local_spares
    {}
  end

  def default_chain
    '10-speed'
  end
  
  def default_tire_size
    raise NotImplementedError
  end
end

class RoadBike < Bicycle
  attr_reader :tape_color

  def post_initialize(args)
    @tape_color = args[:tape_color]
  end

  def default_tire_size
    '23'
  end

  def local_spares
    { :tape_color => tape_color }
  end
end

class MountainBike < Bicycle
  attr_reader :front_shock, :rear_shock

  def post_initialize(args)
    @front_shock = args[:front_shock]
    @rear_shock  = args[:rear_shock]
  end

  def default_tire_size
    '2.1'
  end

  def local_spares
    { :rear_shock => rear_shock }
  end
end

class RecumbentBike < Bicycle
  attr_reader :flag

  def post_initialize(args)
    @flag = args[:flag]
  end

  def local_spares
    { :flag => flag }
  end

  def default_chain
    '9-speed'
  end

  def default_tire_size
    '28'
  end
end

module BicycleInterfaceTest
  def test_responds_to_default_tire_size
    assert_respond_to(@object, :default_tire_size)
  end

  def test_responds_to_default_chain
    assert_respond_to(@object, :default_chain)
  end
  
  def test_responds_to_chain
    assert_respond_to(@object, :chain)
  end

  def test_responds_to_size
    assert_respond_to(@object, :size)
  end

  def test_responds_to_tire_size
    assert_respond_to(@object, :tire_size)
  end

  def test_responds_to_spares
    assert_respond_to(@object, :spares)
  end
end

class BicycleTest < MiniTest::Unit::TestCase
  include BicycleInterfaceTest

  def setup
    @bike = @object = Bicycle.new({:tire_size => 0})
  end
end

class RoadBikeTest < MiniTest::Unit::TestCase
  include BicycleInterfaceTest

  def setup
    @bike = @object = RoadBike.new
  end
end