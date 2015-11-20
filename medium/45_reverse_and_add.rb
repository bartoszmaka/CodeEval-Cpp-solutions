File.open(ARGV[0]).each_line do |line|
    i, line = 0, line.to_i
    while (line.to_s != line.to_s.reverse) do
        line += line.to_s.reverse.to_i
        i += 1
    end
    puts "#{i} #{line}"
end
