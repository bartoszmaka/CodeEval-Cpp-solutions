def fib(n, a = 0, b = 1)
	n.times {|n| a,b = b,a+b}
	a
end

File.open(ARGV[0]).each_line { |line| puts fib(line.to_i) }
