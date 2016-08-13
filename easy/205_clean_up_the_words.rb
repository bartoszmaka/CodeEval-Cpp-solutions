open(ARGV[0]).each_line { |line| puts line.gsub(/[^a-zA-Z]/, ' ').strip.squeeze(' ').downcase }


