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

let T = fIO.readInt()
let n = fIO.readInt(), A = (0..<n).map { _ in fIO.readInt() }
let m = fIO.readInt(), B = (0..<m).map { _ in fIO.readInt() }

var prefixA = [Int](A), prefixB = [Int](B)
for i in 1..<n { prefixA[i] += prefixA[i-1] }
for i in 1..<m { prefixB[i] += prefixB[i-1] }

var mapA = [Int: Int](), mapB = [Int: Int]()
for i in 0..<n {
    for j in 0..<i {
        let subSum = prefixA[i] - prefixA[j]
        mapA[subSum] = mapA[subSum, default: 0] + 1
    }
    mapA[prefixA[i]] = mapA[prefixA[i], default: 0] + 1
}

for i in 0..<m {
    for j in 0..<i {
        let subSum = prefixB[i] - prefixB[j]
        mapB[subSum] = mapB[subSum, default: 0] + 1
    }
    mapB[prefixB[i]] = mapB[prefixB[i], default: 0] + 1
}

var answer = 0
for a in mapA.keys {
    let cntA = mapA[a] ?? 0, cntB = mapB[T-a] ?? 0
    answer += cntA * cntB
}
print(answer)

/*
Testcase

 */
