File.open(ARGV[0]).each_line do |line|
  arr = line.split.map(&:to_f)
  arr.sort.each{ |i| print "%.3f "%i }
  print "\n"
end
