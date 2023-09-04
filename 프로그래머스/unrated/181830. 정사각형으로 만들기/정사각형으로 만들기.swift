import Foundation

func solution(_ arr:[[Int]]) -> [[Int]] {
    var answer = Array(arr)
    let N = answer.count, M = answer[0].count
    
    if N < M { for _ in 0..<M-N { answer.append([Int](repeating:0, count: M)) } }
    else if N > M { answer = answer.map { $0 + [Int](repeating: 0, count: N-M) } }
    return answer
}