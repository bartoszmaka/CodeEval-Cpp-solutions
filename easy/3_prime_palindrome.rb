require 'prime'
number = 0
0.upto(1000) {|i| number = i if (Prime.instance.prime?(i)) && (i.to_s === i.to_s.reverse) }
puts number
