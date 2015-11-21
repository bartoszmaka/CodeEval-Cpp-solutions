__author__ = 'Monek'
import sys


file = open(sys.argv[1], 'r')
for line in file:

    string = "".join(i for i in line if i.isdecimal() or i == ';')# leave only ; and digits
    l = string.split(';')               #put digits in list
    l = l[:-1]                          #do some magic
    intlst = []                         #convert numbers as strings to integers
                                            #***
    for i in l:                             #***
        intlst.append(int(i))               #***
                                            #***
    intlst = sorted(intlst)             #sort list
    intlst.insert(0, 0)                 #put 0 at the beginning

    for i in range(1, len(intlst)-1):
        print(intlst[i]-intlst[i-1], end=",")
    else:
        i += 1
        print(intlst[i]-intlst[i-1])

file.close()
