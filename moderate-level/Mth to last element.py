__author__ = 'Monek'

import sys
file = open(sys.argv[1])
for line in file:
    arr = line.rstrip().split()
    arr.reverse()
    try:
        print(arr[int(arr[0])])
    except IndexError:
        pass
file.close()
