__author__ = 'Monek'


def prime(number):
    for i in range(2, int(number**0.5)+1):
        if number % i == 0: return False
    return True


def palindrome(number):
    return True if str(number) == str(number)[::-1] else False

for i in range(1000, 1, -1):
    if prime(i) & palindrome(i):
        print(i)
        break
