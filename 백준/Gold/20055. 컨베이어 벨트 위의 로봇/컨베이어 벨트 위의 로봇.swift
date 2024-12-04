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

let (N, K) = (fIO.readInt(), fIO.readInt())
var A = (0..<2*N).map { _ in fIO.readInt() }

var answer = 0, count_0 = 0
var start = 0, end = N-1
var robots = [Int](), isThereRobot = [Bool](repeating: false, count: 2*N)

while true {
    answer += 1
    
    //step 1
    start = start == 0 ? 2*N-1 : start-1
    end = end == 0 ? 2*N-1 : end-1
    if let first = robots.first {
        if first == end {
            robots.removeFirst()
            isThereRobot[first] = false
        }
    }

    //step 2
    var isRemove = false
    for i in 0..<robots.count {
        let newLoc = (robots[i] + 1) % (2*N)
        if !isThereRobot[newLoc] && A[newLoc] > 0 {
            A[newLoc] -= 1
            if A[newLoc] == 0 { count_0 += 1 }
            isThereRobot[robots[i]] = false; isThereRobot[newLoc] = true
            robots[i] = newLoc
            if newLoc == end {
                isRemove = true
                isThereRobot[newLoc] = false
            }
        }
    }
    if isRemove { robots.removeFirst() }
    
    //step 3
    if A[start] > 0 {
        robots.append(start)
        isThereRobot[start] = true
        A[start] -= 1
        if A[start] == 0 { count_0 += 1 }
    }
    
    //step 4
    if count_0 >= K { break }
}

print(answer)
/*
Testcase
 
 
 */
