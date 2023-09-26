lst = ['1', '11']
for i in range(32):
	cnt = int(0)
	tmp = ''
	out = ''
	for j in range(len(lst[i + 1])):
		if j == 0:
			cnt += 1
			tmp = lst[i + 1][j]
		elif tmp == lst[i + 1][j]:
			cnt += 1
		else:
			out += str(cnt) + tmp
			tmp = lst[i + 1][j]
			cnt = 1
	out += str(cnt) + tmp
	lst.append(out)

while 1:
	try:
		n = input()
	except EOFError:
		break
	if n == '':
		break
	print(lst[int(n) - 1])
