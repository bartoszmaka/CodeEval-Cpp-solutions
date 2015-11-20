def n_fib(n):
    a = 0
    b = 1
    try:
        for i in range(n-1):
            c = a + b
            a, b = b, c
        else:
            return c
    except Exception:
        if n == 0:
            return 0
        if n == 1:
            return 1


file = open("textinput.txt", 'r')
for line in file:
    print(n_fib(int(line.rstrip())))
file.close()
