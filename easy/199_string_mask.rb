File.open(ARGV[0]).each_line do |line|
  word, mask = line.split
  for i in 0...word.size do
    mask[i] == '1' ? word[i]=word[i].upcase : word[i]=word[i].downcase
  end
  puts word
end
