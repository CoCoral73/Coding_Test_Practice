import sys

def upHeap(i):
    if i == 1:
        return
    global heap
    parent = i // 2
    if heap[parent] > heap[i]:
        swap(parent, i)
        upHeap(parent)

def swap(i, j):
    global heap
    tmp = heap[i]
    heap[i] = heap[j]
    heap[j] = tmp

def downHeap(i, last):
    if 2*i > last:
        return
    global heap
    small = 2*i
    if 2*i+1 <= last and heap[small] > heap[2*i+1]:
        small += 1
    if heap[small] > heap[i]:
        return
    swap(small, i)
    downHeap(small, last)

heap = [0]
last = 0
N = int(input())
for i in range(N):
    x = int(sys.stdin.readline())
    if x > 0:
        heap.append(x)
        last += 1
        upHeap(last)
    else:
        if last == 0:
            print("0")
        else:
            print(heap[1])
            heap[1] = heap[last]
            del heap[last]
            last -= 1
            downHeap(1, last)