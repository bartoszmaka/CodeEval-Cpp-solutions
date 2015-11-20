__author__ = 'Monek'
import re
import sys


def findsum(tab):
    sum = tab.pop()
    flag = False
    for i in range(len(tab)):
        for j in range(i+1, len(tab)):
            if tab[i]+tab[j] == sum:
                if flag:
                    print(';',end="")
                print("{0},{1}".format(tab[i],tab[j]),end="")
                flag = True
    if not flag:
        print("NULL")


file = open(sys.argv[1])
for line in file:
    line = line.rstrip()
    tab = re.split(',', line.replace(';', ','))
    tab = [int(i) for i in tab]
    findsum(tab)
    print()
file.close()
