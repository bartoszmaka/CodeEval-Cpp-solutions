import sys
from math import sqrt

def prime_eratostenes(n):
    if n < 3: return None
    primes = [i for i in range(n)]
    primes[0], primes[1] = 0,0

    for i in range(2,n):
        if i != 0:
            for j in range( (i*2), n, i):
                primes[j] = 0

    primes = [str(p) for p in primes if p != 0]
    result = ','.join(primes)
    return result

file = open(sys.argv[1])
for line in file:
    print(prime_eratostenes(int(line ) ) )
