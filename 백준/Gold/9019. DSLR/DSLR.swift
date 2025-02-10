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

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 만나면 끊김

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }

    @inline(__always) func readByteSequenceWithoutSpaceAndLineFeed() -> [UInt8] {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 만나면 끊김

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return Array(buffer[beginIndex..<(index-1)])
    }
}

class Deque<T> {
    private var enqueue: [T]
    private var dequeue: [T] = []
    
    var isEmpty: Bool { return enqueue.isEmpty && dequeue.isEmpty }
    var count: Int { return enqueue.count + dequeue.count }
    
    init() { enqueue = [T]() }
    init(_ arr: [T]) { enqueue = arr }
    
    func push_front(_ x: T) { dequeue.append(x) }
    func push_back(_ x: T) { enqueue.append(x) }
    func pop_front() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue.removeAll()
        }
        return dequeue.popLast()
    }
    func pop_back() -> T? {
        if enqueue.isEmpty {
            enqueue = dequeue.reversed()
            dequeue.removeAll()
        }
        return enqueue.popLast()
    }
    func front() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue.removeAll()
        }
        return dequeue.last
    }
    func back() -> T? {
        if enqueue.isEmpty {
            enqueue = dequeue.reversed()
            dequeue.removeAll()
        }
        return enqueue.last
    }
    func clear() { enqueue.removeAll(); dequeue.removeAll() }
}

let fIO = FileIO()
//let n = Int(readLine()!)!
//let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }

let T = fIO.readInt()
let dslr = ["", "D", "S", "L", "R"]

func getDSLR(_ n: Int, with: Int) -> Int {
    var num = n
    
    switch with {
    case 1:
        num = (num * 2) % 10000
    case 2:
        num = (num == 0) ? 9999 : num - 1
    case 3:
        num = (n % 1000) * 10 + n / 1000
    default:
        num = (n % 10) * 1000 + n / 10
    }

    return num
}

for _ in 0..<T {
    let (A, B) = (fIO.readInt(), fIO.readInt())
    var isVisited = [Bool](repeating: false, count: 10000)
    
    let queue = Deque<(Int, Int)>()
    queue.push_back((A, 0))
    isVisited[A] = true
    while !queue.isEmpty {
        let (a, result) = queue.pop_front()!
        
        if a == B {
            var answer = ""
            for c in String(result) {
                answer += dslr[Int(String(c))!]
            }
            print(answer)
            break
        }
        
        (1...4).forEach { with in
            let n = getDSLR(a, with: with)
            
            if !isVisited[n] {
                isVisited[n] = true
                queue.push_back((n, result * 10 + with))
            }
        }
    }
}

/*
Testcase

 
 */
