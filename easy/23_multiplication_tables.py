for i in range(1,13):
    for j in range (1,12):
        print('%4i'%(i*j),end='')
    else:
        print('%4i'%(i*(j+1)))
