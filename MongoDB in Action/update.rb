require './config'
require './archiver'

TAGS.each do |tag|
  archive = TweetArchiver.new(tag)
  archive.update
end