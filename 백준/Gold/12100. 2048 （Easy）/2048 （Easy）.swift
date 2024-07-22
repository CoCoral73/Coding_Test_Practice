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

let N = fIO.readInt(), board = (0..<N).map { _ in (0..<N).map { _ in fIO.readInt() } }
var answer = 0

func moveUp(_ copy: inout [[Int]]) {
    for i in 0..<N { //i = 열 번호
        var col = [Int]()
        for j in 0..<N { //j = 행 번호
            if copy[j][i] == 0 { continue }
            if !col.isEmpty && col.last! == copy[j][i] {
                col.append(col.popLast()! * 2)
                col.append(0)
            }
            else { col.append(copy[j][i]) }
        }
        col = col.filter { $0 != 0 }
        for j in 0..<N {
            if j < col.count { copy[j][i] = col[j]; answer = max(answer, col[j]) }
            else { copy[j][i] = 0 }
        }
    }
}
func moveDown(_ copy: inout [[Int]]) {
    for i in 0..<N {
        var col = [Int]()
        for j in stride(from: N-1, through: 0, by: -1) {
            if copy[j][i] == 0 { continue }
            if !col.isEmpty && col.last! == copy[j][i] {
                col.append(col.popLast()! * 2)
                col.append(0)
            }
            else { col.append(copy[j][i]) }
        }
        col = col.filter { $0 != 0 }
        for j in 0..<N {
            if j < col.count { copy[N - 1 - j][i] = col[j]; answer = max(answer, col[j]) }
            else { copy[N - 1 - j][i] = 0 }
        }
    }
}
func moveLeft(_ copy: inout [[Int]]) {
    for i in 0..<N {
        var row = [Int]()
        for j in 0..<N {
            if copy[i][j] == 0 { continue }
            if !row.isEmpty && row.last! == copy[i][j] {
                row.append(row.popLast()! * 2)
                row.append(0)
            }
            else { row.append(copy[i][j]) }
        }
        row = row.filter { $0 != 0 }
        for j in 0..<N {
            if j < row.count { copy[i][j] = row[j]; answer = max(answer, row[j]) }
            else { copy[i][j] = 0 }
        }
    }
}
func moveRight(_ copy: inout [[Int]]) {
    for i in 0..<N {
        var row = [Int]()
        for j in stride(from: N-1, through: 0, by: -1) {
            if copy[i][j] == 0 { continue }
            if !row.isEmpty && row.last! == copy[i][j] {
                row.append(row.popLast()! * 2)
                row.append(0)
            }
            else { row.append(copy[i][j]) }
        }
        row = row.filter { $0 != 0 }
        for j in 0..<N {
            if j < row.count { copy[i][N - 1 - j] = row[j]; answer = max(answer, row[j]) }
            else { copy[i][N - 1 - j] = 0 }
        }
    }
}

func dfs(_ depth: Int, _ board: [[Int]]) {
    if depth == 5 { return }
    //print("### depth : \(depth) ###")
    //board.forEach { print($0) }
    //print()
    
    var copy: [[Int]]
    copy = board
    moveUp(&copy)
    //print("///\(depth) Up///")
    //copy.forEach { print($0) }
    //print()
    if board != copy { dfs(depth + 1, copy) }
    
    copy = board
    moveDown(&copy)
    //print("///\(depth) Down///")
    //copy.forEach { print($0) }
    //print()
    if board != copy { dfs(depth + 1, copy) }

    copy = board
    moveLeft(&copy)
    //print("///\(depth) Left///")
    //copy.forEach { print($0) }
    //print()
    if board != copy { dfs(depth + 1, copy) }
    
    copy = board
    moveRight(&copy)
    //print("///\(depth) Right///")
    //copy.forEach { print($0) }
    //print()
    if board != copy { dfs(depth + 1, copy) }
}

dfs(0, board)
print(answer)