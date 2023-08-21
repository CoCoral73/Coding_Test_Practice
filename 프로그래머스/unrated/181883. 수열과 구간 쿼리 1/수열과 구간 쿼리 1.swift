import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var answer = Array(arr)
    queries.forEach {
        ($0[0]...$0[1]).forEach { answer[$0] += 1 }
    }
    return answer
}