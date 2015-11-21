File.open(ARGV[0]).each_line do |line|
  fizz,buzz,n = line.split.map(&:to_i)
  1.upto(n) do |i|
    if ( i%fizz == 0 ) &( i% buzz == 0 ); print 'FB '
    elsif ( i%fizz == 0 ); print 'F '
    elsif ( i%buzz == 0 ); print 'B '
    else; print "#{i} "
    end
  end
  print "\n"
end
