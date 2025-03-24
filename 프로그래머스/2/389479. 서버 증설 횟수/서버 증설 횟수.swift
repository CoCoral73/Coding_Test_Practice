import Foundation

class Deque {
    private var enqueue: [Int] = []
    private var dequeue: [Int] = []
    
    var isEmpty: Bool {
        return enqueue.isEmpty && dequeue.isEmpty
    }
    var count: Int {
        return enqueue.count + dequeue.count
    }
    
    func push(_ x: Int) {
        enqueue.append(x)
    }
    func front() -> Int? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue = []
        }
        return dequeue.last
    }
    func pop() -> Int? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue = []
        }
        return dequeue.popLast()
    }
}

func solution(_ players:[Int], _ m:Int, _ k:Int) -> Int {
    let server = Deque()
    var count = 0
    
    for i in 0..<24 {
        while !server.isEmpty {
            let front = server.front()!
            if i - front >= k {
                _ = server.pop()
            } else {
                break 
            }
        }
        
        if (players[i] / m) > server.count  {
            let install = (players[i] / m) - server.count
            count += install
            for _ in 0..<install {
                server.push(i)
            }
        }
    }
    return count
}