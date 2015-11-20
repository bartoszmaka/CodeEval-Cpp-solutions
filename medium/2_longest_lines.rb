file = File.open(ARGV[0])
arr = file.read.split("\n")
n = arr.shift.to_i
arr.sort_by!{|line| line.size }
puts arr[-n..-1].reverse
