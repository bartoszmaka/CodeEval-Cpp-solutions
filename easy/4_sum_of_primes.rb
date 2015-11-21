require 'prime'
sum = 0
Prime.first(1000).each{ |i| sum += i }
puts sum
