File.open(ARGV[0]).each_line { |line| puts line.rstrip.split.reverse.join(' ') }
