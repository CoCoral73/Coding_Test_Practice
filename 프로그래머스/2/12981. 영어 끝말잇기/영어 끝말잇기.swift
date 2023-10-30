import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var set = Set<String>()
    for i in 0..<words.count {
        if set.contains(words[i]) { return [i % n + 1, i / n + 1] }
        if i > 0 && (words[i-1].suffix(1) != words[i].prefix(1)) { return [i % n + 1, i / n + 1] }
        set.insert(words[i])
    }
    return [0, 0]
}