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
var isPrime = [Bool](repeating: true, count: N+1), primes = [Int](), answer = 0
isPrime[0] = false; isPrime[1] = false
if N >= 2 {
    for i in 2...N {
        if !isPrime[i] { continue }
        primes.append(i)
        for j in stride(from: 2*i, through: N, by: i) { isPrime[j] = false }
    }
    
    var s = primes.count - 1, e = s, total = primes[s]
    while s >= 0 {
        if total == N {
            answer += 1
            total -= primes[e]
            e -= 1
        }
        else if total < N {
            s -= 1
            if s >= 0 { total += primes[s] }
        }
        else {
            total -= primes[e]
            e -= 1
        }
    }
}
print(N >= 2 ? answer : 0)