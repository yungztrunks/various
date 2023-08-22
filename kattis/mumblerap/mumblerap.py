import re
stringLength = input("string length: ")
string = input("string:")
x = re.sub('\D', '#', string)
y = []
y = x.split('#')
y.sort()
stringLength = len(y)
print(y[stringLength-1])