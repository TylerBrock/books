class Schedule
  def scheduled?(schedulable, start_date, end_date)
    puts "This #{schedulable.class} " +
         "is not scheduled\n" +
         "  between #{start_date} and #{end_date}"
  end
end

module Schedulable
  attr_writer :schedule

  def schedule
    @schedule ||= ::Schedule.new
  end

  def schedulable?(start_date, end_date)
    !scheduled?(start_date - lead_days, end_date)
  end

  def scheduled?(start_date, end_date)
    schedule.scheduled?(self, start_date, end_date)
  end

  def lead_days
    0
  end
end

class Bicycle
  include Schedulable
  attr_reader :schedule, :size, :chain, :tire_size
  def initialize(args={})
    @schedule  = args[:schedule]  || Schedule.new
    @size      = args[:size]
    @chain     = args[:chain]
    @tire_size = args[:tire_size]
  end

  def lead_days
    1
  end
end

class Vehicle
  include Schedulable

  def lead_days
    3
  end
end

class Mechanic
  include Schedulable

  def lead_days
    4
  end
end

require 'date'
starting = Date.parse('2015/09/04')
ending   = Date.parse('2015/09/10')

b = Bicycle.new
b.schedulable?(starting, ending)

v = Vehicle.new
v.schedulable?(starting, ending)

v = Mechanic.new
v.schedulable?(starting, ending)