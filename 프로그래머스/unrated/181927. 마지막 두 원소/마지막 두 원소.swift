import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    var answer = [Int](num_list)
    var last = num_list.count-1
    if num_list[last] > num_list[last-1] { answer.append(num_list[last]-num_list[last-1]) }
    else { answer.append(num_list[last]*2) }
    return answer
}