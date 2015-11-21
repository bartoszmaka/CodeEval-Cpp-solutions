from math import sqrt

def is_prime(number):
	for i in range(2,int(sqrt(number))+1):
		if number%i == 0:
			return 0
	else:
		return number


i = 2
count = 0
total = 0

while count < 1000:
	temp = is_prime(i)
	if temp != 0:
		total += temp
		count += 1
	i += 1
	
print(total)
