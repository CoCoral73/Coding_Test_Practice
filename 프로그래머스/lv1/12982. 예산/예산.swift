import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
    var sum = d.reduce(0, +), answer = d.count, d = d
    d.sort()
    while sum > budget {
        sum -= d.removeLast()
        answer -= 1
    }
    return answer
}