import sys
from collections import deque

n, m = map(int, input().split())
P = []
for _ in range(n):
    p = list(map(int, sys.stdin.readline().split()))
    P.append(p)

V = [[False]*m for _ in range(n)]
Q = deque()
cnt = 0
MAX = 0
for i in range(n):
    for j in range(m):
        if P[i][j] == 0 or V[i][j] == True:
            continue
        Q.append((i, j))
        V[i][j] = True
        area = 0
        while len(Q) > 0:
            r, c = Q.popleft()
            area += 1
            if r-1 >= 0 and V[r-1][c] == False and P[r-1][c] == 1:
                Q.append((r-1, c))
                V[r-1][c] = True
            if r+1 < n and V[r+1][c] == False and P[r+1][c] == 1:
                Q.append((r+1, c))
                V[r+1][c] = True
            if c-1 >= 0 and V[r][c-1] == False and P[r][c-1] == 1:
                Q.append((r, c-1))
                V[r][c-1] = True
            if c+1 < m and V[r][c+1] == False and P[r][c+1] == 1:
                Q.append((r, c+1))
                V[r][c+1] = True
        MAX = max(MAX, area)
        cnt += 1
print(cnt)
print(MAX)