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
let HATK = fIO.readInt()
let room = (0..<N).map { _ in (fIO.readInt(), fIO.readInt(), fIO.readInt()) }

var s = 1, e = Int.max-1, answer = Int.max
while s <= e {
    let m = (s + e) / 2
    var HP = m, ATK = HATK, flag = true
    for i in 0..<N {
        if room[i].0 == 1 {     //몬스터
            let I_to_You = room[i].2 % ATK == 0 ? room[i].2 / ATK : room[i].2 / ATK + 1
            let You_to_I = HP % room[i].1 == 0 ? HP / room[i].1 : HP / room[i].1 + 1
            
            if I_to_You > You_to_I { flag = false; break }
            HP -= room[i].1 * (I_to_You - 1)
        }
        else {      //포션
            ATK += room[i].1
            HP = min(m, HP + room[i].2)
        }
    }
    if flag { answer = min(answer, m); e = m - 1 }
    else { s = m + 1 }
}
print(answer)