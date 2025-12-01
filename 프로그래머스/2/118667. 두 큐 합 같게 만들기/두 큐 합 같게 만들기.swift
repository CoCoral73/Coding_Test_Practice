import Foundation

struct Queue {
    private var enqueue: [Int] = []
    private var dequeue: [Int] = []
    
    init(_ arr: [Int]) {
        enqueue = arr
    }
    
    mutating func insert(_ x: Int) {
        enqueue.append(x)
    }
    mutating func pop() -> Int? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue = []
        }
        return dequeue.popLast()
    }
}

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    let max = (queue1.count + queue2.count) * 2
    var q1 = Queue(queue1), q2 = Queue(queue2)
    var sum1 = queue1.reduce(0, +), sum2 = queue2.reduce(0, +)
    
    if (sum1 + sum2) % 2 == 1 { return -1 }
    
    var answer: Int = 0
    while answer < max {
        if sum1 < sum2 {
            let pop = q2.pop()!
            q1.insert(pop)
            sum1 += pop
            sum2 -= pop
        } else if sum1 > sum2 {
            let pop = q1.pop()!
            q2.insert(pop)
            sum1 -= pop
            sum2 += pop
        } else {
            return answer
        }
        answer += 1
    }
    
    return -1
}