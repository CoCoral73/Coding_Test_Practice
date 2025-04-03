import Foundation

struct Heap<T> {
    private var elements: [T] = []
    private let sortFunction: (T, T) -> Bool
    
    init(_ sortFunction: @escaping (T,T) -> Bool) {
        self.sortFunction = sortFunction
    }
    
    var isEmpty: Bool { elements.isEmpty }
    var count: Int { elements.count }
    
    func peek() -> T? { elements.first }
    mutating func insert(_ x: T) {
        elements.append(x)
        shiftUp(from: self.count - 1)
    }
    mutating func remove() -> T? {
        guard !isEmpty else { return nil }
        
        if elements.count == 1 { return elements.removeLast() }
        else {
            let top = elements[0]
            elements[0] = elements.removeLast()
            shiftDown()
            return top
        }
    }
    mutating private func shiftUp(from index: Int) {
        var child = index, parent = (child - 1) / 2
        let value = elements[index]
        
        while child > 0 && sortFunction(value, elements[parent]) {
            elements[child] = elements[parent]
            child = parent
            parent = (parent - 1) / 2
        }
        elements[child] = value
    }
    mutating private func shiftDown() {
        var parent = 0
        
        while true {
            let left = parent * 2 + 1
            let right = left + 1
            var selected = parent
            
            if left < self.count && sortFunction(elements[left], elements[selected]) {
                selected = left
            }
            if right < self.count && sortFunction(elements[right], elements[selected]) {
                selected = right
            }
            
            if selected == parent { return }
            
            elements.swapAt(parent, selected)
            parent = selected
        }
    }
    
}

func solution(_ n:Int, _ k:Int, _ enemy:[Int]) -> Int {
    if k >= enemy.count || n >= enemy.reduce(0, +) { return enemy.count }
    
    var sum: Int = 0, k = k
    var pq = Heap<Int> { $0 > $1 }
    var round: Int = 0
    
    while true {
        while sum <= n {
            if round == enemy.count { return round }
            sum += enemy[round]
            pq.insert(enemy[round])
            round += 1
        }

        if k > 0 {
            let peek = pq.remove()!
            sum -= peek
            k -= 1
        } else {
            if n == sum { return round }
            else { return round - 1 }
        }
    }
    return round
}