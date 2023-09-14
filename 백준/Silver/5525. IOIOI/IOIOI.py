N = int(input())
M = int(input())
S = list(input())

P = ['I','O','I'] + ['O','I']*(N-1)

size = 2*N+1
cnt = 0
i = 0
while i <= M-size:
    if S[i:i+size] == P[:]:
        cnt += 1
        i += 2
    else:
        i += 1
print(cnt)