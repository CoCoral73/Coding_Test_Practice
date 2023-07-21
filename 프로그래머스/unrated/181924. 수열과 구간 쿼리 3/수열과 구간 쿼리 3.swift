import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var answer = arr
    for k in 0..<queries.count {
        let i = queries[k][0]
        let j = queries[k][1]
        let tmp = answer[i]
        answer[i] = answer[j]
        answer[j] = tmp
    }
    return answer
}