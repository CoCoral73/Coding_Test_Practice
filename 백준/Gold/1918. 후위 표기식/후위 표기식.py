import sys
from collections import deque

def level(ch):
	if ch == '+' or ch == '-':
		return 1
	elif ch == '*' or ch == '/':
		return 2
	elif ch == '(':
		return 3
	return 4
	
A = input()
rst = []
stack = deque()

for i in A:
	if i >= 'A' and i <= 'Z':
		rst.append(i)
	else:
		if len(stack) == 0:
			stack.append(i)
		else:
			j = len(stack)-1
			if i == ')':
				while stack[j] != '(':
					rst.append(stack.pop())
					j -= 1
				stack.pop()
			elif stack[j] == '(' or level(stack[j]) < level(i):
				stack.append(i)
			else:
				while j >= 0 and level(stack[j]) >= level(i):
					if stack[j] == '(':
						break
					rst.append(stack.pop())
					j -= 1
				stack.append(i)
			#print(stack)

i = len(stack)
while i > 0:
	rst.append(stack.pop())
	i -= 1

for i in rst:
	if i != '(' and i != ')':
		print(i,end='')