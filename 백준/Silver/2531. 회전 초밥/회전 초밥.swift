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

let N = fIO.readInt(), (d, k, c) = (fIO.readInt(), fIO.readInt(), fIO.readInt())
let sushi = (0..<N).map { _ in fIO.readInt() }
var count = [Int](repeating: 0, count: d + 1)

var s = 0, e = 0, result = 0, answer = 0
while e < k {
    let n = sushi[e]
    if count[n] == 0 { result += 1 }
    count[n] += 1
    e = (e + 1) % N
}
//s 포함, e 미포함

while s < N {
    if count[c] == 0 { answer = max(answer, result + 1) }
    else { answer = max(answer, result) }
    let sn = sushi[s], en = sushi[e]
    if count[sn] == 1 { result -= 1 }
    count[sn] -= 1
    s += 1
    if count[en] == 0 { result += 1 }
    count[en] += 1
    e = (e + 1) % N
}
print(answer)