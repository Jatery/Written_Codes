import math

t = int(input())
for i in range(t):
	n = int(input())
	print(2 * n - 2 ** int(math.log(n, 2) + 1) + 1)
