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
var nums = [Int: Int]()
for _ in 0..<N {
    let n = fIO.readInt()
    if nums[n] == nil { nums.updateValue(1, forKey: n) }
    else { nums[n]! += 1 }
}
let keys = nums.keys.sorted()
var result = [String](), answer = [String]()
func dfs(_ depth: Int, _ start: Int) {
    if depth == M {
        answer.append(result.joined(separator: " "))
        return
    }
    
    for i in start..<keys.count {
        let key = keys[i]
        if nums[key] == 0 { continue }
        nums[key]! -= 1
        result.append(String(key))
        dfs(depth + 1, i)
        result.removeLast()
        nums[key]! += 1
    }
}

dfs(0, 0)
print(answer.joined(separator: "\n"))