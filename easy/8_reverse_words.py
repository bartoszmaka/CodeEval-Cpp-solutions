import sys
file = open(sys.argv[1])
for line in file:
    print(" ".join(reversed(line.rstrip().split())))
file.close()
