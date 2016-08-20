File.open(ARGV[0]).each_line do |line|
  virus, antivirus = line.split "|"
  virus = virus.split(' ').inject(0) { |sum, hex| sum + hex.to_i(16) }
  antivirus = antivirus.split(' ').inject(0) { |sum, bin| sum + bin.to_i(2) }
  puts antivirus >= virus ? "True" : "False"
end
