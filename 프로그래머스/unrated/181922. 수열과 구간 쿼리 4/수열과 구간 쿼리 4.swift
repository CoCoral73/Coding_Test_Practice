import Foundation

func solution(_ arr:[Int], _ queries: [[Int]]) -> [Int] {
    var answer = arr
    queries.forEach {
        var i = $0[0]
        while i <= $0[1] {
            if i % $0[2] == 0 { answer[i] += 1 }
            i += 1
        }
    }
    return answer
}