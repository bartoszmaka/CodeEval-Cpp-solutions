File.open(ARGV[0]).each_line do |line|
    str,regex = line.split(',').map(&:strip)
    str.gsub!(/[#{regex}]/, '')
    puts str
end
