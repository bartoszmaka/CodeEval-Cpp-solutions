import sys

source = "file.txt"
file = open(sys.argv[1], 'r')

for line in file:
    pos=line.find(',')          ##  Hello World,r
    newline=line[pos-1::-1]     ##  dlroW olleH
    case=line[pos+1:pos+2]      ##  r
    pos=newline.find(case)
    if case in newline:
        print(len(newline)-(pos+1))
    else:
        print(-1)
file.close()
