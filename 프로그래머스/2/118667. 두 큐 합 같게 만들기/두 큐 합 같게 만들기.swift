import Foundation

class Queue<T> {
    private var front_index: Int
    var front: T?
    var back: T?
    var Q: [T]
    var count: Int
    
    init() {
        front_index = 0
        front = nil
        back = nil
        Q = [T]()
        count = 0
    }
    init(_ arr: [T]) {
        front_index = 0
        front = arr.first!
        Q = arr
        count = arr.count
    }
    func push(_ x:T) {
        back = x
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
    if (queue1.reduce(0, +) + queue2.reduce(0, +)) % 2 != 0 { return -1 }
    var queue = Queue<(q1: Queue<Int>, s1: Int64, q2: Queue<Int>, s2: Int64, count: Int)>()
    
    queue.push((q1: Queue(queue1), s1: queue1.reduce(Int64(0), { $0 + Int64($1) }), q2: Queue(queue2), s2: queue2.reduce(Int64(0), { $0 + Int64($1) }), count: 0))
    while queue.count != 0 {
        let (q1, s1, q2, s2, count) = queue.pop()
        if s1 == s2 { return count }
        if count > (q1.count + q2.count) * 2 { break }
        if s1 < s2 {
            let front2 = q2.pop()
            q1.push(front2)
            if q2.count != 0 {
                queue.push((q1: q1, s1: s1+Int64(front2), q2: q2, s2: s2-Int64(front2), count: count+1))
            }
        }
        else {
            let front1 = q1.pop()
            q2.push(front1)
            if q1.count != 0 {
                queue.push((q1: q1, s1: s1-Int64(front1), q2: q2, s2: s2+Int64(front1), count: count+1))
            }
        }
    }
    return -1
}