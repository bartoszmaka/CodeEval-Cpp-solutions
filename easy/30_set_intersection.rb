File.open(ARGV[0]).each_line do |line|
  left, right = line.strip.split(';').map { |s| s.split(',') }
  left.keep_if { |e| right.include? e }
  puts left.empty? ? '' : left.join(',')
end
