import Foundation

func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
    let score = score.sorted(by: >)
    var answer = 0, index = 0
    while true {
        if index + m - 1 >= score.count { break }
        answer += score[index+m-1] * m
        index += m
    }
    return answer
}