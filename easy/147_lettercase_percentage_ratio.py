__author__ = 'Monek'
import sys


def do_stuff(word):
    low = 0
    for sign in word:
        if sign.islower():
            low += 1
    try:
        low = low/len(word)*100
    except ZeroDivisionError:
        low = 100
    print("lowercase: %.2f uppercase: %.2f" % (low, (100-low)))
    return None


file = open(sys.argv[1], 'r')

for line in file:
    do_stuff(line.rstrip())

file.close()
