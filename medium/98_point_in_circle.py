__author__ = 'Monek'
import sys


file = open(sys.argv[1])
for line in file:
    line = line.rstrip()
    line = "".join([i for i in line if i.isnumeric() or i == '-' or i == ' ' or i == '.'])
#   args goes : circle.x,y,r point.x,y
#                     [0,1,2.......3,4]
    args = line.split()
    args = [float(i) for i in args]
#   sqrt ((x2-x1)^2+(y2-y1)^2 )
    dist = ((args[3]-args[0])**2+(args[4]-args[1])**2)**0.5
    if dist < args[2]:
        print('true')
    else:
        print('false')
file.close()
