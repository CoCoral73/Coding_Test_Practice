import Foundation

func solution(_ keymap:[String], _ targets:[String]) -> [Int] {
    var alphabet = [Int](repeating: 101, count: 26)
    keymap.forEach { key in
        key.enumerated().forEach {
            let n = $0.element.asciiValue! - Character("A").asciiValue!
            alphabet[Int(n)] = min(alphabet[Int(n)], $0.offset + 1)
        }
    }
    return targets.map { tg in
        var result = 0
        for i in 0..<tg.count {
            let n = tg[tg.index(tg.startIndex, offsetBy: i)].asciiValue! - Character("A").asciiValue!
            if alphabet[Int(n)] == 101 { return -1 }
            result += alphabet[Int(n)]
        }
        return result
    }
}