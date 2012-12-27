require 'rubygems'
require 'mongo'
require 'sinatra'

require './config'

configure do
  db = Mongo::Connection.new[DATABASE_NAME]
  TWEETS = db[COLLECTION_NAME]
end

get '/' do
  if params['tag']
    selector = {:tags => params['tag']}
  else
    selector = {}
  end
  
  @tweets = TWEETS.find(selector).sort(['id', -1])
  
  erb :tweets
end