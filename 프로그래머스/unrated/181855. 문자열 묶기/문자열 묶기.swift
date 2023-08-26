import Foundation

func solution(_ strArr:[String]) -> Int {
    var dict = [Int: Int]()
    var answer = 0
    strArr.forEach {
        dict[$0.count] = dict[$0.count] == nil ? 1 : dict[$0.count]! + 1
        answer = max(answer, dict[$0.count]!)
    }
    return answer
}
