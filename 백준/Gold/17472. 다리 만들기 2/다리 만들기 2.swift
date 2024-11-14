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
let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]

let (N, M) = (fIO.readInt(), fIO.readInt())
var grid = (0..<N).map { _ in (0..<M).map { _ in fIO.readInt() } }
var isVisited = [[Bool]](repeating: [Bool](repeating: false, count: M), count: N)

func dfs(_ r: Int, _ c: Int, _ n: Int) {
    isVisited[r][c] = true
    grid[r][c] = n
    
    for i in 0..<4 {
        let newR = r + dr[i], newC = c + dc[i]
        if newR < 0 || newR >= N || newC < 0 || newC >= M { continue }
        if grid[newR][newC] == 0 || isVisited[newR][newC] { continue }
        dfs(newR, newC, n)
    }
}

//numbering
var island_num = 1
for i in 0..<N {
    for j in 0..<M {
        if grid[i][j] == 0 || isVisited[i][j] { continue }
        dfs(i, j, island_num)
        island_num += 1
    }
}
let island_count = island_num - 1
var graph = [[(Int, Int)]](repeating: [(Int, Int)](), count: island_count + 1)

func getLength(_ r: Int, _ c: Int, _ d: Int) -> (Int, Int)? {
    var length = 0
    
    let myNum = grid[r][c]
    var newR = r, newC = c
    while true {
        newR += dr[d]; newC += dc[d]
        if newR < 0 || newR >= N || newC < 0 || newC >= M { return nil }
        if grid[newR][newC] == myNum { return nil }
        if grid[newR][newC] != 0 {
            if length >= 2 { return (grid[newR][newC], length) }
            else { return nil }
        }
        length += 1
    }
}

for i in 0..<N {
    for j in 0..<M {
        if grid[i][j] == 0 { continue }
        for d in 0..<4 {
            guard let edge = getLength(i, j, d) else { continue }
            if edge.0 < grid[i][j] { continue }
            graph[grid[i][j]].append(edge)
            graph[edge.0].append((grid[i][j], edge.1))
        }
    }
}

func sortFunction(_ a: (Int, Int), _ b: (Int, Int)) -> Bool { return a.1 < b.1 }
var heap = Heap<(Int, Int)>(sortFunction)
var isMST = [Bool](repeating: false, count: island_count + 1)
isMST[1] = true
for edge in graph[1] { heap.insert(edge) }

var count = 0, answer = 0
while !heap.isEmpty && count < island_count - 1 {
    let (another_num, cost) = heap.remove()!
    
    if isMST[another_num] { continue }
    isMST[another_num] = true
    answer += cost
    count += 1
    for edge in graph[another_num] {
        if !isMST[edge.0] { heap.insert(edge) }
    }
}
print(count == island_count - 1 ? answer : -1)