import Foundation

struct Heap<T> {
    private var arr: [T] = []
    private let sortFunction: (T, T) -> Bool 
    
    var isEmpty: Bool { arr.isEmpty }
    var count: Int { arr.count }
    
    init(_ sortFunction: @escaping (T, T) -> Bool) {
        self.sortFunction = sortFunction
    }
    
    func peek() -> T? { arr.first }
    mutating func insert(_ x: T) {
        arr.append(x)
        shiftUp(self.count - 1)
    }
    mutating func remove() -> T? {
        if self.isEmpty {
            return nil 
        }
        
        if self.count == 1 { return arr.removeLast() }
        
        let top = arr.first
        arr[0] = arr.removeLast()
        shiftDown(0)
        return top
    }
    
    private mutating func shiftUp(_ index: Int) {
        var child = index, parent = (index - 1) / 2
        let value = arr[index]
        
        while child > 0 && sortFunction(value, arr[parent]) {
            arr[child] = arr[parent]
            child = parent
            parent = (parent - 1) / 2
        }
        arr[child] = value
    }
    
    private mutating func shiftDown(_ index: Int) {
        var parent = index
        
        while true {
            let left = parent*2 + 1, right = left + 1
            var target = parent
            
            if left < self.count && sortFunction(arr[left], arr[target]) {
                target = left
            }
            if right < self.count && sortFunction(arr[right], arr[target]) {
                target = right
            }
            
            if target == parent { return }
            arr.swapAt(parent, target)
            parent = target
        }
    }
}

//최단경로
func solution(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var graph = [[Int]](repeating: [Int](repeating: Int.max, count: N), count: N)
    
    for info in road {
        let (a, b, c) = (info[0]-1, info[1]-1, info[2])
        
        graph[a][b] = min(graph[a][b], c)
        graph[b][a] = min(graph[b][a], c)
    }
    
    var distance = [Int](repeating: Int.max, count: N)
    var pq = Heap<(Int, Int)> { $0.0 < $1.0 }
    
    distance[0] = 0
    pq.insert((0, 0))
    while !pq.isEmpty {
        let (cost, dest) = pq.remove()!
        
        if cost > distance[dest] { continue }
        
        for i in 0..<N {
            if graph[dest][i] == Int.max { continue }
            if graph[dest][i] + cost < distance[i] {
                distance[i] = graph[dest][i] + cost
                pq.insert((distance[i], i))
            }
        }
    }
    
    return distance.filter { $0 <= k }.count 
}