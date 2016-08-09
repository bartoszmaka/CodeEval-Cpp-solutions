File.open(ARGV[0]).each_line do |line|
  word, char = line.strip.split','
  index = word.rindex(char)
  puts index == nil ? "-1" : index
end
