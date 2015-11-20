import string
import sys


def do_stuff(line):
    col = set(line.lower())
    letters = set(string.ascii_lowercase)
    result = letters.difference(col)
    if result:
        result=sorted(result)
        result="".join(result)
        return result
    else:
        return("NULL")

file = open(sys.argv[1],'r')
for buffer in file:
    print(do_stuff(buffer.rstrip()))
file.close()
