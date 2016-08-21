File.open(ARGV[0]).each_line do |line|
  numbers = line.strip.gsub(' ', '').chars.map(&:to_i)
  numbers.map!.with_index { |n, i| i % 2 == 0 ? n*2 : n }
  puts numbers.inject(0, :+) % 10 == 0 ? "Real" : "Fake"
end
