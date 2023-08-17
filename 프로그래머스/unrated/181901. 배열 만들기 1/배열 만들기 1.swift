import Foundation

func solution(_ n:Int, _ k:Int) -> [Int] {
    var answer = [Int]()
    for i in stride(from: k, through: n, by: k) { answer.append(i) }
    return answer
}