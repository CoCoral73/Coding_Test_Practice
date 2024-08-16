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
class Deque<T> {
    private var enqueue: [T]
    private var dequeue: [T] = []
    
    var isEmpty: Bool { return enqueue.isEmpty && dequeue.isEmpty }
    var count: Int { return enqueue.count + dequeue.count }
    
    init() { enqueue = [T]() }
    init(_ arr: [T]) { enqueue = arr }
    
    func push_front(_ x: T) { dequeue.append(x) }
    func push_back(_ x: T) { enqueue.append(x) }
    func pop_front() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue.removeAll()
        }
        return dequeue.popLast()
    }
    func pop_back() -> T? {
        if enqueue.isEmpty {
            enqueue = dequeue.reversed()
            dequeue.removeAll()
        }
        return enqueue.popLast()
    }
    func front() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue.removeAll()
        }
        return dequeue.last
    }
    func back() -> T? {
        if enqueue.isEmpty {
            enqueue = dequeue.reversed()
            dequeue.removeAll()
        }
        return enqueue.last
    }
    func clear() { enqueue.removeAll(); dequeue.removeAll() }
}

let fIO = FileIO()
let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]
typealias RC = (r: Int, c: Int)

let (R, C) = (fIO.readInt(), fIO.readInt())
var maze = [[Character]](), isVisited = [[Int]](repeating: [Int](repeating: Int.max, count: C), count: R)
let J_Queue = Deque<RC>(), F_Queue = Deque<RC>()
for i in 0..<R {
    let line = [Character](fIO.readString())
    maze.append(line)
    for j in 0..<C {
        if line[j] == "J" { J_Queue.push_back((i, j)); isVisited[i][j] = 0 }
        else if line[j] == "F" { F_Queue.push_back((i, j)); isVisited[i][j] = 0 }
    }
}

var answer = Int.max
while !J_Queue.isEmpty {
    let F_cnt = F_Queue.count
    for _ in 0..<F_cnt {
        let (r, c) = F_Queue.pop_front()!
        
        for i in 0..<4 {
            let (rr, cc) = (r + dr[i], c + dc[i])
            if rr < 0 || rr >= R || cc < 0 || cc >= C { continue }
            if maze[rr][cc] == "#" { continue }
            if isVisited[rr][cc] <= isVisited[r][c] + 1 { continue }
            isVisited[rr][cc] = isVisited[r][c] + 1
            maze[rr][cc] = "F"
            F_Queue.push_back((rr, cc))
        }
    }
    
    let J_cnt = J_Queue.count
    for _ in 0..<J_cnt {
        let (r, c) = J_Queue.pop_front()!
        
        for i in 0..<4 {
            let (rr, cc) = (r + dr[i], c + dc[i])
            if rr < 0 || rr >= R || cc < 0 || cc >= C { answer = min(answer, isVisited[r][c] + 1); continue }
            if maze[rr][cc] == "#" || maze[rr][cc] == "F" { continue }
            if isVisited[rr][cc] <= isVisited[r][c] + 1 { continue }
            isVisited[rr][cc] = isVisited[r][c] + 1
            J_Queue.push_back((rr, cc))
        }
    }
}
print(answer != Int.max ? answer : "IMPOSSIBLE")