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
let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]

typealias Info = (r: Int, c: Int, type: Int)
let N = fIO.readInt(), M = fIO.readInt()
var map = [[Int]](repeating: [Int](repeating: 0, count: M), count: N)
var cctvs = [Info]()
for i in 0..<N {
    for j in 0..<M {
        let type = fIO.readInt()
        map[i][j] = type
        if type >= 1 && type <= 5 { cctvs.append((i, j, type)) }
    }
}

var direction = [Int](repeating: 0, count: cctvs.count)
let numOfDirection = [0, 4, 2, 4, 4, 1]
var answer = N*M

func simulation(_ copy: inout [[Int]]) {
    func simul1(_ r: Int, _ c: Int, _ d: Int) {
        var r = r, c = c
        while true {
            r = r + dr[d]; c = c + dc[d]
            if r < 0 || r >= N || c < 0 || c >= M { break }
            if copy[r][c] == 6 { break }
            copy[r][c] = 7
        }
    }
    func simul2(_ r: Int, _ c: Int, _ d: Int) {
        switch d {
        case 0:
            simul1(r, c, 0); simul1(r, c, 2)
        default:
            simul1(r, c, 1); simul1(r, c, 3)
        }
    }
    func simul3(_ r: Int, _ c: Int, _ d: Int) {
        switch d {
        case 0:
            simul1(r, c, 0); simul1(r, c, 1)
        case 1:
            simul1(r, c, 1); simul1(r, c, 2)
        case 2:
            simul1(r, c, 2); simul1(r, c, 3)
        default:
            simul1(r, c, 3); simul1(r, c, 0)
        }
    }
    func simul4(_ r: Int, _ c: Int, _ d: Int) {
        switch d {
        case 0:
            simul1(r, c, 0); simul1(r, c, 1); simul1(r, c, 2)
        case 1:
            simul1(r, c, 1); simul1(r, c, 2); simul1(r, c, 3)
        case 2:
            simul1(r, c, 2); simul1(r, c, 3); simul1(r, c, 0)
        default:
            simul1(r, c, 3); simul1(r, c, 0); simul1(r, c, 1)
        }
    }
    func simul5(_ r: Int, _ c: Int, _ d: Int) {
        simul1(r, c, 0); simul1(r, c, 1); simul1(r, c, 2); simul1(r, c, 3)
    }
    
    for i in 0..<cctvs.count {
        let (r, c) = (cctvs[i].r, cctvs[i].c)
        let type = cctvs[i].type, d = direction[i]
        switch type {
        case 1: simul1(r, c, d)
        case 2: simul2(r, c, d)
        case 3: simul3(r, c, d)
        case 4: simul4(r, c, d)
        default: simul5(r, c, d)
        }
    }
}
func dfs(_ depth: Int) {
    if depth == cctvs.count {
        var copy = [[Int]](map)
        simulation(&copy)
        answer = min(answer, copy.reduce(0, { return $0 + $1.filter({ $0 == 0 }).count }))
        return
    }
    
    for i in 0..<numOfDirection[cctvs[depth].type] {
        direction[depth] = i
        dfs(depth + 1)
    }
}
dfs(0)
print(answer)