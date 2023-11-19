import Foundation

class Queue<T> {
    private var front_index: Int
    var front: T?
    var Q: [T]
    var count: Int
    
    init(_ arr: [T]) {
        front_index = 0
        front = arr.first!
        Q = arr
        count = arr.count
    }
    func push(_ x:T) {
        Q.append(x)
        count += 1
    }
    func pop() -> T {
        front_index += 1
        front = front_index >= Q.count ? nil : Q[front_index]
        count -= 1
        return Q[front_index-1]
    }
}

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    var Q1 = Queue(queue1), Q2 = Queue(queue2), size = queue1.count * 2
    var sum1 = queue1.reduce(0, +), sum2 = queue2.reduce(0, +)
    
    if (sum1 + sum2) % 2 == 1 { return -1 }
    
    var answer = 0
    while true {
        if answer > size * 2 { break }
        if sum1 < sum2 {
            let front2 = Q2.pop()
            Q1.push(front2)
            sum1 += front2
            sum2 -= front2
        }
        else if sum1 > sum2 {
            let front1 = Q1.pop()
            Q2.push(front1)
            sum1 -= front1
            sum2 += front1
        }
        else {
            return answer
        }
        answer += 1
    }
    return -1
}