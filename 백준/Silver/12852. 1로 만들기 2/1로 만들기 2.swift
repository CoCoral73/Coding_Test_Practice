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

let N = fIO.readInt()
var dp = [0, 0, 1, 1]
for i in stride(from: 4, through: N, by: 1) {
    dp.append(Int.max)
    if i % 3 == 0 { dp[i] = min(dp[i], dp[i/3] + 1) }
    if i % 2 == 0 { dp[i] = min(dp[i], dp[i/2] + 1) }
    dp[i] = min(dp[i], dp[i-1] + 1)
}
print(dp[N])

var x = N
while x >= 1 {
    print(x, terminator: " ")
    if x == 1 { break }
    if x % 3 == 0 { if dp[x/3] == dp[x] - 1 { x /= 3; continue } }
    if x % 2 == 0 { if dp[x/2] == dp[x] - 1 { x /= 2; continue } }
    if dp[x-1] == dp[x] - 1 { x -= 1 }
}