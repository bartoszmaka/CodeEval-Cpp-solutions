def foo (line)
    arr = line.split('')
    arr.keep_if{|c| arr.count(c) == 1}[0]
end

File.open(ARGV[0]).each_line { |line| puts foo(line) }
