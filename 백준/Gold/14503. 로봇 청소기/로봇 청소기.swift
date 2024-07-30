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

let N = fIO.readInt(), M = fIO.readInt()
var (r, c, d) = (fIO.readInt(), fIO.readInt(), fIO.readInt())

let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]
let room = (0..<N).map { _ in (0..<M).map { _ in fIO.readInt() } }
var isCleaned = [[Bool]](repeating: [Bool](repeating: false, count: M), count: N)
var answer = 0

while true {
    if !isCleaned[r][c] { answer += 1 }
    isCleaned[r][c] = true
    
    var flag = true
    for i in 0..<4 {
        let R = r + dr[i], C = c + dc[i]
        if room[R][C] == 1 || isCleaned[R][C] { continue }
        flag = false
    }
    
    if flag { //청소 안된게 없음 2번 경우
        let R = r + dr[(d + 2) % 4], C = c + dc[(d + 2) % 4]
        if room[R][C] == 1 { break }
        r = R; c = C
    }
    else {
        d = (d + 3) % 4
        let R = r + dr[d], C = c + dc[d]
        if room[R][C] != 1 && !isCleaned[R][C] { r = R; c = C }
    }
}

print(answer)