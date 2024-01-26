import sys

def t1(x, y):
	global N, M
	global paper
	
	v1 = v2 = 0
	if y+3 < M:
		v1 = paper[x][y]+paper[x][y+1]+paper[x][y+2]+paper[x][y+3]
	if x+3 < N:
		v2 = paper[x][y]+paper[x+1][y]+paper[x+2][y]+paper[x+3][y]
	if v1 > 0 and v2 > 0:
		return v1 if v1 > v2 else v2
	elif v1 > 0:
		return v1
	elif v2 > 0:
		return v2
	else:
		return 0

def t2(x, y):
	global N, M
	global paper
	
	v = 0
	if x+1 < N and y+1 < M:
		v = paper[x][y]+paper[x+1][y]+paper[x][y+1]+paper[x+1][y+1]
	return v

def t3(x, y):
	global N, M
	global paper
	
	MAX = 0
	if x+2 < N:
		v = paper[x][y]+paper[x+1][y]+paper[x+2][y]
		if y+1 < M:
			v1 = v + paper[x+2][y+1]
			v3 = v + paper[x][y+1]
			if MAX < v1:
				MAX = v1
			if MAX < v3:
				MAX = v3
		if y-1 >= 0:
			v2 = v + paper[x+2][y-1]
			v4 = v + paper[x][y-1]
			if MAX < v2:
				MAX = v2
			if MAX < v4:
				MAX = v4
	if x+1 < N:
		v = paper[x][y]+paper[x+1][y]
		if y+2 < M:
			v1 = v + paper[x][y+1] + paper[x][y+2]
			v3 = v + paper[x+1][y+1] + paper[x+1][y+2]
			if MAX < v1:
				MAX = v1
			if MAX < v3:
				MAX = v3
		if y-2 >= 0:
			v2 = v + paper[x][y-1] + paper[x][y-2]
			v4 = v + paper[x+1][y-1] + paper[x+1][y-2]
			if MAX < v2:
				MAX = v2
			if MAX < v4:
				MAX = v4
	return MAX
	
def t4(x,y):
	global N, M
	global paper
	
	MAX = 0
	if x+2 < N:
		v = paper[x][y] + paper[x+1][y]
		if y+1 < M:
			v1 = v + paper[x+1][y+1] + paper[x+2][y+1]
			if MAX < v1:
				MAX = v1
		if y-1 >= 0:
			v2 = v + paper[x+1][y-1] + paper[x+2][y-1]
			if MAX < v2:
				MAX = v2
	if x+1 < N:
		v = paper[x][y]
		if y+2 < M:
			v3 = v + paper[x][y+1] + paper[x+1][y+1] + paper[x+1][y+2]
			if MAX < v3:
				MAX = v3
		if y-2 >= 0:
			v4 = v + paper[x][y-1] + paper[x+1][y-1] + paper[x+1][y-2]
			if MAX < v4:
				MAX = v4
	return MAX

def t5(x,y):
	global N, M
	global paper
	
	MAX = 0
	v = paper[x][y]
	if y-1 >= 0 and y+1 < M:
		if x+1 < N:
			v1 = v + paper[x][y-1] + paper[x][y+1] + paper[x+1][y]
			if MAX < v1:
				MAX = v1
		if x-1 >= 0:
			v2 = v + paper[x][y-1] + paper[x][y+1] + paper[x-1][y]
			if MAX < v2:
				MAX = v2
	if x-1 >= 0 and x+1 < N:
		if y+1 < M:
			v3 = v + paper[x-1][y] + paper[x+1][y] + paper[x][y+1]
			if MAX < v3:
				MAX = v3
		if y-1 >= 0:
			v4 = v + paper[x-1][y] + paper[x+1][y] + paper[x][y-1]
			if MAX < v4:
				MAX = v4
	return MAX
	
N, M = map(int, input().split())
paper = []
for i in range(N):
	line = list(map(int, sys.stdin.readline().split()))
	paper.append(line)
	
MAX = 0
for i in range(N):
	for j in range(M):
		value = t1(i,j)
		if MAX < value:
			MAX = value
		value = t2(i,j)
		if MAX < value:
			MAX = value
		value = t3(i,j)
		if MAX < value:
			MAX = value
		value = t4(i,j)
		if MAX < value:
			MAX = value
		value = t5(i,j)
		if MAX < value:
			MAX = value

print(MAX)