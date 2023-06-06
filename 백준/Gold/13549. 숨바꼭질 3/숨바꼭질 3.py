import heapq
import sys
INF = 999999999

def dijkstra(N, K):
    D = [INF]*(K+2)
    D[N] = 0
    Q = []
    heapq.heappush(Q, (0, N))

    while len(Q) > 0:
        t, x = heapq.heappop(Q)
        if t >= D[K]:
            continue
        if 2*x < K+2 and t < D[2*x]:
            D[2*x] = t
            heapq.heappush(Q, (D[2*x], 2*x))
        if x+1 < K+1 and t + 1 < D[x+1]:
            D[x+1] = t+1
            heapq.heappush(Q, (D[x+1], x+1))
        if x-1 > N // 2 and t + 1 < D[x-1]:
            D[x-1] = t+1
            heapq.heappush(Q, (D[x-1], x-1))
    return D[K]

N, K = map(int, input().split())
if N >= K:
    print(N-K)
else:
    print(dijkstra(N, K))