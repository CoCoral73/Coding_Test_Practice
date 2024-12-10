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
//let n = Int(readLine()!)!
//let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }

let (N, M) = (fIO.readInt(), fIO.readInt())
let A = (0..<N).map { _ in fIO.readInt() }

var prefixSum = [Int](A), count = [Int](repeating: 0, count: M)
var answer = 0
for i in 0..<N {
    if i > 0 { prefixSum[i] += prefixSum[i-1] }
    if prefixSum[i] % M == 0 { answer += 1 }
    answer += count[prefixSum[i] % M]
    count[prefixSum[i] % M] += 1
}
print(answer)

/*
Testcase
 3
 1 2 3 1 2
 1 3 6 7 9
 3 1 2 3 9
 3 4 6 9 18
 
 */
