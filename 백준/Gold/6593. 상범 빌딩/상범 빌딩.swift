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
let dl = [0, 0, 0, 0, -1, 1], dr = [-1, 0, 1, 0, 0, 0], dc = [0, 1, 0, -1, 0, 0]
typealias LRC = (l: Int, r: Int, c: Int)

while true {
    let (L, R, C) = (fIO.readInt(), fIO.readInt(), fIO.readInt())
    if L | R | C == 0 { break }
    
    var building = [[[Character]]]()
    let Queue = Deque<LRC>()
    var isVisited = [[[Int]]](repeating: [[Int]](repeating: [Int](repeating: Int.max, count: C), count: R), count: L)
    for i in 0..<L {
        var floor = [[Character]]()
        for j in 0..<R {
            let line = [Character](fIO.readString())
            floor.append(line)
            for k in 0..<C {
                if line[k] == "S" { Queue.push_back((i, j, k)); isVisited[i][j][k] = 0 }
            }
        }
        building.append(floor)
    }
    
    var answer = Int.max
    while !Queue.isEmpty {
        let (l, r, c) = Queue.pop_front()!
        if building[l][r][c] == "E" {
            answer = min(answer, isVisited[l][r][c])
            continue
        }
        
        for i in 0..<6 {
            let (ll, rr, cc) = (l + dl[i], r + dr[i], c + dc[i])
            if ll < 0 || ll >= L || rr < 0 || rr >= R || cc < 0 || cc >= C { continue }
            if building[ll][rr][cc] == "#" { continue }
            if isVisited[ll][rr][cc] <= isVisited[l][r][c] + 1 { continue }
            isVisited[ll][rr][cc] = isVisited[l][r][c] + 1
            Queue.push_back((ll, rr, cc))
        }
    }
    
    print(answer == Int.max ? "Trapped!" : "Escaped in \(answer) minute(s).")
}
