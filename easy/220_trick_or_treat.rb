costumes = {Vampires: 3, Zombies: 4, Witches: 5}
File.open(ARGV[0]).each_line do |line|
  treats = Hash[*line.split(/[:,]/).map(&:strip)]
  houses = treats.delete('Houses').to_i
  kids = treats.each_value.inject(0) { |sum, v| sum + v.to_i }
  treats = treats.each.map { |k, v| v.to_i * costumes[k.to_sym] }.inject(0, :+)
  puts ((treats * houses) / kids).round
end
