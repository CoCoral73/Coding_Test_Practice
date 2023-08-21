import Foundation

func solution(_ num_list:[Int]) -> Int {
    var odd = 0
    var even = 0
    for i in 0..<num_list.count {
        if i % 2 == 0 { even += num_list[i] }
        else { odd += num_list[i] }
    }
    return max(odd, even)
}