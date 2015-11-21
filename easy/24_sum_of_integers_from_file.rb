sum = 0
File.open(ARGV[0]).each_line { |line| sum += line.to_i}
puts sum
