import Foundation

func solution(_ arr:[Int], _ query:[Int]) -> [Int] {
    var answer = [Int](arr)
    for i in 0..<query.count {
        if i % 2 == 0 { answer.removeSubrange((query[i]+1)...) }
        else { answer.removeSubrange((..<query[i])) }
    }
    return answer
}