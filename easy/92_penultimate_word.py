import sys

file = open(sys.argv[1])
for line in file:
    arr = line.rstrip().split()
    print(arr[-2])
file.close()
