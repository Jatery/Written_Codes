
t = int(input())
for i in range(t):
	lst = []
	n = int(input())
	for j in range(n):
		a, b = input().split()
		a = int(a)
		b = int(b)
		if a > b:
			continue
		lst.append([b, a])
	lst.sort()
	cnt = 0
	time = 0
	f = [0]
	k = 0
	for j in range(lst[len(lst) - 1][0] + 1):
		if j > 0:
			f.append(f[j-1])
		while k < len(lst) and lst[k][0] <= j:
			f[j] = max(f[j], f[j - lst[k][1]] + 1)
			k += 1
	#print(f)
	print(f[lst[-1][0]])

	#dp
	#以期限sort，dp轉移式：
	#f(k) = max(f(k), f(k - time) + 1)
