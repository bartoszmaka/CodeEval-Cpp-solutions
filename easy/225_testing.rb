File.open(ARGV[0]).each_line do |line|
  development, design = line.strip.split(" | ")
  diff = 0
  development.length.times do |i|
    diff += 1 if development[i] != design[i]
  end
  case diff
  when 0
    puts "Done"
  when (1..2)
    puts "Low"
  when (3..4)
    puts "Medium"
  when (5..6)
    puts "High"
  else
    puts "Critical"
  end
end
