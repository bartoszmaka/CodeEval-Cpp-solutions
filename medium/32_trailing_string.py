import sys

def foo(words):
    return 1 if words[1] in words[0] else 0

file = open('32_testing_cases.txt')

for line in file:
    line = list( line.strip().split(',') )
    print( foo(line) )
