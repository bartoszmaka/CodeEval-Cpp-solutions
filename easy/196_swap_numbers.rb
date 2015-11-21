File.open(ARGV[0]).each_line do |line|
  words = line.split
  words.each{|word| word[0],word[-1] = word[-1], word[0]; print word<<' '}
  print "\n"
end
