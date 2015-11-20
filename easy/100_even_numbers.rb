File.open(ARGV[0]).each_line { |line| puts line.to_i % 2 == 0 ? 1:0 }
