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

func getOrder(_ c: Character) -> Int{
    return Int(c.asciiValue! - 65)
}
let R = fIO.readInt(), C = fIO.readInt()
var board = [[Int]](repeating: [Int](repeating: 0, count: C), count: R)
(0..<R).forEach { r in
    let line = [Character](fIO.readString())
    (0..<C).forEach { c in
        board[r][c] = getOrder(line[c])
    }
}
var isVisited = 0

let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]
var answer = 0
func dfs(_ r: Int, _ c: Int, _ depth: Int) {
    answer = max(answer, depth)
    
    for i in 0..<4 {
        let newR = r + dr[i], newC = c + dc[i]
        if newR < 0 || newR >= R || newC < 0 || newC >= C { continue }
        let x = board[newR][newC]
        if isVisited & (1 << x) != 0 { continue }
        isVisited |= 1 << x
        dfs(newR, newC, depth + 1)
        isVisited &= ~(1 << x)
    }
}

isVisited |= 1 << board[0][0]
dfs(0, 0, 1)
print(answer)