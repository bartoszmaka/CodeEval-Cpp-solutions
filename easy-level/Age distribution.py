import sys

def answer(age):
	if age in range(0,3):
		return('Still in Mama\'s arms')
	elif age in range(3,5):
		return('Preschool Maniac')
	elif age in range(5,12):
		return('Elementary school')
	elif age in range(12,15):
		return('Middle school')
	elif age in range(15,19):
		return('High school')
	elif age in range(19,23):
		return('College')
	elif age in range(23,66):
		return('Working for the man')
	elif age in range(66,101):
		return('The Golden Years')
	else:
		return('This program is for humans')


file= open("textinput.txt",'r')
for line in file:
    print(answer(int(line.rstrip())))


file.close()



