File.open(ARGV[0]).each_line { |line| puts Integer(line, 16) }
