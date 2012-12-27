require 'rubygems'
require 'mongo'

@con = Mongo::Connection.new
@db = @con['tutorial']
@users = @db['users']

id = @users.save({"lastname" => "knuth"})
@users.find_one({"_id" => id})

smith = {"last_name" => "smith", "age" => 30}
jones = {"last_name" => "jones", "age" => 40}

smith_id = @users.insert(smith)
jones_id = @users.insert(jones)

p @users.find_one({"_id" => smith_id})
p @users.find_one({"_id" => jones_id})

p @users.find({"last_name" => "smith"})
p @users.find({"age" => {"$gt" => 20}})

cursor = @users.find({"age" => {"$gt" => 20}})

cursor.each do |doc|
  puts doc["last_name"]
end

cursor = @users.find({"age" => {"$gt" => 20}})

while doc = cursor.next
  puts doc["last_name"]
end

@users.update({"last_name" => "smith"}, {"$set" => {"city" => "Chicago"}})

@users.update({"last_name" => "smith"}, {"$set" => {"city" => "New York"}}, :multi => true)

@users.remove({"age" => {"$gte" => 40}})

@users.remove

connection = Mongo::Connection.new
db = connection['tutorial']
db.drop_collection('users')

@admin_db = @con['admin']
@admin_db.command({"listDatabases" => 1})

@users.insert({"last_name" => "james"}, :safe => true)
