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

let (N, M) = (fIO.readInt(), fIO.readInt())
var matrix = (0..<N).map { _ in [Character](fIO.readString()) }

let Queue = Deque<(Int, Int)>([(0, 0)])
var isVisited = [[[Int]]](repeating: [[Int]](repeating: [Int](repeating: Int.max, count: M), count: N), count: 2)
isVisited[0][0][0] = 1

var answer = Int.max
while !Queue.isEmpty {
    let (r, c) = Queue.pop_front()!
    if r == N - 1 && c == M - 1 {
        answer = min(answer, min(isVisited[0][r][c], isVisited[1][r][c]))
        continue
    }
    
    for i in 0..<4 {
        let (R, C) = (r + dr[i], c + dc[i])
        if R < 0 || R >= N || C < 0 || C >= M { continue }
        if matrix[R][C] == "0" {
            var flag = false
            if isVisited[0][r][c] != Int.max && isVisited[0][R][C] > isVisited[0][r][c] + 1 {
                isVisited[0][R][C] = isVisited[0][r][c] + 1
                flag = true
            }
            if isVisited[1][r][c] != Int.max && isVisited[1][R][C] > isVisited[1][r][c] + 1 {
                isVisited[1][R][C] = isVisited[1][r][c] + 1
                flag = true
            }
            if flag { Queue.push_back((R, C)) }
        }
        else {
            if isVisited[0][r][c] != Int.max && isVisited[1][R][C] > isVisited[0][r][c] + 1 {
                isVisited[1][R][C] = isVisited[0][r][c] + 1
                Queue.push_back((R, C))
            }
        }
    }
}
print(answer == Int.max ? -1 : answer)