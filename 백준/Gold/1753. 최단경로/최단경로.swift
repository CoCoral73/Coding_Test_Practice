import Foundation

//빠른 입출력
final class FileIO {
    private let buffer:[UInt8]
    private var index: Int = 0

    init(fileHandle: FileHandle = FileHandle.standardInput) {
        
        buffer = Array(try! fileHandle.readToEnd()!)+[UInt8(0)] // 인덱스 범위 넘어가는 것 방지
    }

    @inline(__always) private func read() -> UInt8 {
        defer { index += 1 }

        return buffer[index]
    }

    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true

        while now == 10
                || now == 32 { now = read() } // 공백과 줄바꿈 무시
        if now == 45 { isPositive.toggle(); now = read() } // 음수 처리
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }

        return sum * (isPositive ? 1:-1)
    }

    @inline(__always) func readString() -> String {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }

    @inline(__always) func readByteSequenceWithoutSpaceAndLineFeed() -> [UInt8] {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return Array(buffer[beginIndex..<(index-1)])
    }
}

//Comparable 빼도 됨
struct Heap<T> {
    private var elements: [T] = []
    private let sortFunction: (T, T) -> Bool
    //>: 최대 힙, <: 최소 힙
    
    init(_ sortFunction: @escaping (T, T) -> Bool) {
        self.sortFunction = sortFunction
    }
    
    var isEmpty: Bool { return elements.isEmpty }
    var count: Int { return elements.count }
    func peek() -> T? { return elements.first }
    
    mutating func insert(_ value: T) {
        elements.append(value)
        shiftUp(from: self.count - 1)
    }
    mutating func remove() -> T? {
        guard !isEmpty else { return nil }
        if elements.count == 1 { return elements.removeFirst() }
        else {
            let top = elements[0]
            elements[0] = elements.removeLast()
            shiftDown()
            return top
        }
    }
    private mutating func shiftUp(from index: Int) {
        var child = index, parent = self.parent(of: index)
        let value = elements[index]
        
        while child > 0 && sortFunction(value, elements[parent]) {
            elements[child] = elements[parent]
            child = parent
            parent = self.parent(of: parent)
        }
        elements[child] = value
    }
    private mutating func shiftDown() {
        var parent = 0
        
        while true {
            let left = self.leftChild(of: parent)
            let right = self.rightChild(of: parent)
            var selected = parent
            
            if left < self.count && sortFunction(elements[left], elements[selected]) {
                selected = left
            }
            if right < self.count && sortFunction(elements[right], elements[selected]) {
                selected = right
            }
            if parent == selected { return }
            
            elements.swapAt(parent, selected)
            parent = selected
        }
    }
    
    private func parent(of index: Int) -> Int { return (index - 1) / 2 }
    private func leftChild(of index: Int) -> Int { return 2 * index + 1 }
    private func rightChild(of index: Int) -> Int { return 2 * index + 2 }
}

let fIO = FileIO()
//let n = Int(readLine()!)!
//let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }

var pq = Heap<(Int, Int)> { return $0.0 < $1.0 }

let (V, E) = (fIO.readInt(), fIO.readInt()), K = fIO.readInt()
var graph = [[(Int, Int)]](repeating: [(Int, Int)](), count: V+1)
var distance = [Int](repeating: Int.max, count: V+1)

for _ in 0..<E {
    let (u, v, w) = (fIO.readInt(), fIO.readInt(), fIO.readInt())
    graph[u].append((w, v))
}

distance[K] = 0
pq.insert((0, K))

while !pq.isEmpty {
    let (w, x) = pq.remove()!
    //if distance[x] < w { continue }
    
    for (cost, y) in graph[x] {
        if w + cost < distance[y] {
            distance[y] = w + cost
            pq.insert((w + cost, y))
        }
    }
}

for i in 1...V {
    if distance[i] == Int.max { print("INF") }
    else { print(distance[i]) }
}
/*
Testcase

 */
