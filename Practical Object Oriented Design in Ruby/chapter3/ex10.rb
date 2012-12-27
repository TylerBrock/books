module SomeFramework
  class Gear
    attr_reader :chainring, :cog, :wheel
    def initialize(chainring, cog, wheel)
      @chainring = chainring
      @cog       = cog
      @wheel     = wheel
    end

    def gear_inches
      ratio * diameter
    end

    def diameter
      wheel.diameter
    end

    def ratio
      chainring / cog.to_f
    end
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

  def circumfrence
    diameter * Math::PI
  end
end

module GearWrapper
  def self.gear(args)
    SomeFramework::Gear.new(
      args[:chainring],
      args[:cogs],
      args[:wheel]
    )
  end
end

GearWrapper.gear(
  :chainring => 52,
  :cog       => 11,
  :wheel     => Wheel.new(26, 1.5)).gear_inches