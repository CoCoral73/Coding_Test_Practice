import Foundation

func solution(_ arr:[Int], _ k:Int) -> [Int] {
    var answer = [Int]()
    for i in 0..<arr.count {
        if !answer.contains(arr[i]) { answer.append(arr[i]) }
        if answer.count == k { break }
    }
    if answer.count < k { answer += Array(repeating: -1, count: k-answer.count) }
    return answer
}