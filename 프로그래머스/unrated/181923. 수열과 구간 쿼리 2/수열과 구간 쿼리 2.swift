import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var answer = [Int]()
    queries.forEach {
        var value = 1000001
        for i in $0[0]...$0[1] {
            value = arr[i] > $0[2] ? min(value, arr[i]) : value
        }
        answer.append(value != 1000001 ? value : -1)
    }
    return answer
}