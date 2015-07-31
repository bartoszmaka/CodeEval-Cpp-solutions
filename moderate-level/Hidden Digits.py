__author__ = 'Monek'
import sys


letters = {
    'a': 0,
    'b': 1,
    'c': 2,
    'd': 3,
    'e': 4,
    'f': 5,
    'g': 6,
    'h': 7,
    'i': 8,
    'j': 9,
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9
}


def reveal(text):
    found = False
    for i in text:
        try:
            print(letters[i],end="")
            found = True
        except KeyError:
            continue
    if not found:
        print("NONE",end="")
    print()


file = open(sys.argv[1])
for line in file:
    line = line.rstrip()
    reveal(line)

file.close()
