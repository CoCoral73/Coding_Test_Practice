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
let N = fIO.readInt(), nums = (0..<N).map { _ in fIO.readInt() }
var op = (0..<4).map { _ in fIO.readInt() }
var MAX = Int.min, MIN = Int.max

func dfs(_ depth: Int, _ last: Int) {
    if depth == N-1 {
        MAX = max(MAX, last)
        MIN = min(MIN, last)
        return
    }
    
    for i in 0..<4 {
        if op[i] == 0 { continue }
        op[i] -= 1
        var result = last
        switch i {
        case 0:
            result += nums[depth + 1]
        case 1:
            result -= nums[depth + 1]
        case 2:
            result *= nums[depth + 1]
        default:
            result /= nums[depth + 1]
        }
        dfs(depth + 1, result)
        op[i] += 1
    }
}

dfs(0, nums[0])
print(MAX)
print(MIN)