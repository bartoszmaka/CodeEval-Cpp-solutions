File.open(ARGV[0]).each_line do |line|
  longest = line.strip.split(' ').sort_by { |word| -word.length }.first
  longest.chars.each_with_index do |char, index|
    index.times { |n| print '*' }
    print char + " "
  end
  print "\n"
end
