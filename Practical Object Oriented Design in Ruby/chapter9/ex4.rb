require 'minitest/autorun'

class DiameterDouble
  def diameter
    10
  end
end

class Wheel
  attr_reader :rim, :tire
  def initialize(rim, tire)
    @rim  = rim
    @tire = tire
  end

  def diameter
    rim + (tire * 2)
  end
end

class Gear
  attr_reader :chainring, :cog, :wheel
  def initialize(args)
    @chainring = args[:chainring]
    @cog       = args[:cog]
    @wheel     = args[:wheel]
  end

  def gear_inches
    ratio * wheel.diameter
  end

  def ratio
    chainring / cog.to_f
  end
end

class WheelTest < MiniTest::Unit::TestCase
  def setup
    @wheel = Wheel.new(26, 1.5)
  end

  def test_implements_the_diameterizable_interface
    assert_respond_to(@wheel, :diameter)
  end

  def test_calculates_diameter
    wheel = Wheel.new(26, 1.5)

    assert_in_delta(29, wheel.diameter, 0.01)
  end
end

class GearTest < MiniTest::Unit::TestCase
  def test_calculate_gear_inches
    gear = Gear.new(
      :chainring => 52,
      :cog       => 11,
      :wheel     => DiameterDouble.new
    )

    assert_in_delta(47.27, gear.gear_inches, 0.01)
  end
end