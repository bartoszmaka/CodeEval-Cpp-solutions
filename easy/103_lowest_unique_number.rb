File.open(ARGV[0]).each_line do |line|
  line = line.strip.split ' '
  lowest_unique = line.select { |n| line.count(n) == 1 }.sort.first
  puts lowest_unique == nil ? 0 : line.index(lowest_unique).to_i + 1
end
