import Foundation

func solution(_ n:Int, _ m:Int, _ section:[Int]) -> Int {
    var dict = Dictionary(uniqueKeysWithValues: zip(section, [Bool](repeating:false, count:section.count)))
    var now = 0, answer = 0
    while now < section.count {
        var first = now
        while now < section.count {
            if section[now]-section[first]+1 <= m { now += 1 }
            else { break }
        }
        answer += 1
    }
    return answer
}