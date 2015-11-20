__author__ = 'Monek'
import sys


file = open(sys.argv[1])
for line in file:
    numbers = line.split()
    numbers = [float(i) for i in numbers]
    for i in sorted(numbers):
        print("{0:.3f}".format(i), end=" ")
    else:
        print()
file.close()
