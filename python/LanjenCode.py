while 1:
	try:
		n = input()
	except EOFError:
		break
	if n == '':
		break
	n, t = n.split()
	reference = input()
	if t == 'a':
		for i in range(int(n)):
			sentence = input()
			output = ""
			for j in range(len(sentence)):
				if ord(sentence[j]) >= ord('A') and ord(sentence[j]) <= ord('Z'):
					output += reference[ord(sentence[j]) - ord('A')]
				else:
					output += sentence[j];
			print(output)
	else:
		for i in range(int(n)):
			sentence = input()
			output = ""
			for j in range(len(sentence)):
				if ord(sentence[j]) >= ord('A') and ord(sentence[j]) <= ord('Z'):
					output += chr(reference.find(sentence[j]) + ord('A'))
				else:
					  output += sentence[j]
			print(output)
