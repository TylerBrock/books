class Song
	@@plays = 0
	attr_reader :name, :artist, :duration
	attr_writer :duration
	def initialize(name, artist, duration)
		@name			=name
		@artist		=artist
		@duration	=duration
		@plays = 0
	end
	def to_s
		"Song: #@name--#@artist (#@duration)"
	end
	def duration_in_minutes
		@duration/60.0 # force floating point
	end
	def duration_in_minutes=(new_duration)
		@duration = (new_duration*60).to_i
	end
	def play
		@plays += 1
		@@plays += 1
		"This song: #@plays plays. Total #@@plays plays."
	end
end

song = Song.new("Bicylops", "Fleck", 260)

puts song.inspect
puts song.to_s

class KaraokeSong < Song
	def initialize(name, artist, duration, lyrics)
		super(name, artist, duration)
		@lyrics = lyrics
	end
	def to_s
		super + " [#@lyrics]"
	end
end

song = KaraokeSong.new("My Way", "Sinatra", 225, "And now, the...")
puts song.to_s

s1 = Song.new("Song1", "Artist1", 234) # test songs..
s2 = Song.new("Song2", "Artist2", 545)
puts s1.play
puts s1.play
puts s2.play

class SongList
	MAX_TIME = 5*60 # 5 minutes

	def SongList.is_too_long(song)
		return song.duration > MAX_TIME
	end
end

puts SongList.is_too_long(s1)
puts SongList.is_too_long(s2)

class MyLogger
	private_class_method :new
	@@logger = nil
	def MyLogger.create
		@@logger = new unless @@logger
		@@logger
	end
end

puts MyLogger.create.object_id
puts MyLogger.create.object_id

require 'test/unit'

class WordIndex
	def initialize
		@index = {}
	end
	def add_to_index(obj, *phrases)
		phrases.each do |phrase|
			phrase.scan(/\w[-\w']+/) do |word|
				word.downcase!
				@index[word] = [] if @index[word].nil?
				@index[word].push(obj)
			end
		end
	end
	def lookup(word)
		@index[word.downcase]
	end
end

class SongList
	def initialize
		@songs = Array.new
		@index = WordIndex.new
	end
	def append(song)
		@songs.push(song)
		@index.add_to_index(song, song.name, song.artist)
		self
	end
	def delete_first
		@songs.shift
	end
	def delete_last
		@songs.pop
	end
	def [](index)
		@songs[index]
	end
	def with_title(title)
		@songs.find { |song| title == song.name }
	end
	def lookup(word)
		@index.lookup(word)
	end
end

class TestSongList < Test::Unit::TestCase
	def test_delete
		list = SongList.new
		s1 = Song.new('title1', 'artist1', 1)
		s2 = Song.new('title2', 'artist2', 2)
		s3 = Song.new('title3', 'artist3', 3)
		s4 = Song.new('title4', 'artist4', 4)
		list.append(s1).append(s2).append(s3).append(s4)
		assert_equal(s1, list[0])
		assert_equal(s3, list[2])
		assert_nil(list[9])
		assert_equal(s1, list.delete_first)
		assert_equal(s2, list.delete_first)
		assert_equal(s4, list.delete_last)
		assert_equal(s3, list.delete_last)
		assert_nil(list.delete_last)
	end
end

File.open("/Users/tbrock/Development/learning-ruby/songdata") do |song_file|
	songs = SongList.new
	song_file.each do |line|
		file, length, name, title = line.chomp.split(/\s*\|\s*/)
		name.squeeze!(" ")
		mins, secs = length.scan(/\d+/)
		songs.append(Song.new(title, name, mins.to_i*60+secs.to_i))
	end
	puts songs.lookup("Fats")
	puts songs.lookup("ain't")
	puts songs.lookup("RED")
	puts songs.lookup("WoRlD")
end

class VU
	include Comparable
	attr :volume
	def initialize(volume) # 0..9
		@volume = volume
	end
	def inspect
		'#' * @volume
	end
	# Support for ranges
	def <=>(other)
		self.volume <=> other.volume
	end
	def succ
		raise(IndexError, "Volume too big") if @volume >= 9
		VU.new(@volume.succ)
	end
end
