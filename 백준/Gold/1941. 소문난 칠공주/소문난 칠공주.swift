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

let fIO = FileIO()
let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]

let matrix = (0..<5).map { _ in [Character](fIO.readString()) }
var isVisited = [[Bool]](repeating: [Bool](repeating: false, count: 5), count: 5)
var check = Set<[Int]>()

var answer = 0;
func backtracking(_ depth: Int, _ s: Int, _ y: Int, _ princess: [Int]) {
    if depth == 6 {
        if !check.contains(princess.sorted()) {
            answer += 1
            check.insert(princess.sorted())
        }
        
        return
    }
    
    var copy = [(Int)](princess)
    princess.forEach {
        for i in 0..<4 {
            let (r, c) = ($0 / 5 + dr[i], $0 % 5 + dc[i])
            if r < 0 || r >= 5 || c < 0 || c >= 5 { continue }
            if isVisited[r][c] { continue }
            
            copy.append(r*5 + c)
            isVisited[r][c] = true
            if matrix[r][c] == "S" { backtracking(depth + 1, s + 1, y, copy) }
            else if y + 1 <= 3 { backtracking(depth + 1, s, y + 1, copy) }
            isVisited[r][c] = false
            copy.removeLast()
        }
    }
}

for i in 0..<5 {
    for j in 0..<5 {
        isVisited[i][j] = true
        if matrix[i][j] == "S" { backtracking(0, 1, 0, [i*5 + j]) }
        else { backtracking(0, 0, 1, [i*5 + j]) }
        isVisited[i][j] = false
    }
}

print(answer)