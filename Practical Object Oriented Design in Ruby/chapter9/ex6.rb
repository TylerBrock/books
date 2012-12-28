require 'minitest/autorun'

class Trip
  attr_reader :bicycles, :customers, :vehicle

  # this 'mechanic' argument could be of any class
  def prepare(preparers)
    preparers.each {|preparer| preparer.prepare_trip(self)}
  end
end

# when every preparer is a Duke
# that responds to 'prepare_trip'
class Mechanic
  def prepare_trip(trip)
    trip.bicycles.each {|bicycle| prepare_bicycle(bicycle)}
  end

  def prepare_bicycle(bicycle)
    # ...
  end
end

class TripCoordinator
  def prepare_trip(trip)
    buy_food(trip.customers)
  end

  def buy_food(customers)
    # ...
  end
end

class Driver
  def prepare_trip(trip)
    vehicle = trip.vehicle
    gas_up(vehicle)
    fill_water_tank(vehicle)
  end

  def gas_up(vehicle)
    # ...
  end

  def fill_water_tank(vehicle)
    # ...
  end
end

module PreparerInterfaceTest
  def test_implements_the_preparer_interface
    assert_respond_to(@object, :prepare_trip)
  end
end

class MechanicTest < MiniTest::Unit::TestCase
  include PreparerInterfaceTest

  def setup
    @mechanic = @object = Mechanic.new
  end
end

class TripCoordinatorTest < MiniTest::Unit::TestCase
  include PreparerInterfaceTest

  def setup
    @trip_coordinator = @object = TripCoordinator.new
  end
end

class DriverTest < MiniTest::Unit::TestCase
  include PreparerInterfaceTest

  def setup
    @driver = @object = Driver.new
  end
end

class TripTest < MiniTest::Unit::TestCase
  def test_requests_trip_preparation
    @preparer = MiniTest::Mock.new
    @trip     = Trip.new
    @preparer.expect(:prepare_trip, nil, [@trip])

    @trip.prepare([@preparer])
    @preparer.verify
  end
end