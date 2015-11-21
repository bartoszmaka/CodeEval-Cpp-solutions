__author__ = 'Monek'
import sys

file = open(sys.argv[1])
for line in file:
    xy = [int(i) for i in line.split()]
    if xy[0] == xy[2] and xy[1] == xy[3]:
        print("here")
    else:
        if xy[1] != xy[3]:
            print("N", end="") if xy[3] > xy[1] else print("S", end="")
        if xy[0] != xy[2]:
            print("E", end="")if xy[2] > xy[0] else print("W", end="")
        print()
file.close()
