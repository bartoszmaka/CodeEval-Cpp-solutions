__author__ = 'Monek'

import sys

file = open(sys.argv[1], 'r')
total = 0
for line in file:
    total += (int(line.rstrip()))
print(total)
file.close()
