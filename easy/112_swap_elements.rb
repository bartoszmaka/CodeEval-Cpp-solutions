File.open(ARGV[0]).each_line do |line|
  str,keys = line.split(':')
  str = str.split(' ')
  keys.split(',').each do |k|
    a,b = k.split('-').map(&:to_i)
    str[a], str[b] = str[b], str[a]
  end
  str.each{|c| print c.to_s + ' '}; print "\n"
end
