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

var gears = (0..<4).map { _ in [Character](fIO.readString()) }

func rotateAGear(_ gear: inout [Character], _ d: Int) {
    if d == 1 {
        var new = [Character]([gear.popLast()!])
        new.append(contentsOf: gear)
        gear = new
    }
    else {
        gear.append(gear.removeFirst())
    }
}
func rotateAll(_ n: Int, _ d: Int) {
    var dir = [Int](repeating: 0, count: 4)
    dir[n] = d
    //left
    for i in stride(from: n-1, through: 0, by: -1) {
        if gears[i][2] != gears[i+1][6] { dir[i] = -dir[i+1] }
        else { break }
    }
    
    //right
    for i in stride(from: n+1, through: 3, by: 1) {
        if gears[i][6] != gears[i-1][2] { dir[i] = -dir[i-1] }
        else { break }
    }
    
    for i in 0..<4 {
        if dir[i] == 0 { continue }
        rotateAGear(&gears[i], dir[i])
    }
}
func getScore() -> Int {
    var score = 0
    for i in 0..<4 {
        if gears[i][0] == "0" { continue }
        score += (0..<i).reduce(1, { (r, _) in return r * 2 })
    }
    return score
}

let K = fIO.readInt()
for _ in 0..<K {
    let (n, d) = (fIO.readInt(), fIO.readInt())
    rotateAll(n-1, d)
}
print(getScore())