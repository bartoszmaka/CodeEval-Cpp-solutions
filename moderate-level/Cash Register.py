__author__ = 'Monek'
import sys


table = {
    1: 'PENNY',
    5: 'NICKEL',
    10: 'DIME',
    25: 'QUARTER',
    50: 'HALF DOLLAR',
    100: 'ONE',
    200: 'TWO',
    500: 'FIVE',
    1000: 'TEN',
    2000: 'TWENTY',
    5000: 'FIFTY',
    10000: 'ONE HUNDRED'
    }

values = [10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1]


def calc_change(change):
    if change < 0:
        print("ERROR")
        return None
    if change == 0:
        print("ZERO")
        return None

    for value in values:
            if value <= change:
                change -= value
                print(table[value],end='')
                break

    while change > 0:
        for value in values:
            if value <= change:
                change -= value
                print(','+table[value],end='')
                break
    print()
    return None


file = open(sys.argv[1])
for line in file:
    monies = [100*float(i) for i in line.split(';')]
    monies = [int(i) for i in monies]

    calc_change(monies[1] - monies[0])

file.close()
