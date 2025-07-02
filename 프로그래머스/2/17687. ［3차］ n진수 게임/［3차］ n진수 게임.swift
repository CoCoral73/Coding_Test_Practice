import Foundation 

func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    var nums: [String] = []
    var answer: [String] = []
    
    var num: Int = 0
    while nums.count < m*t - (m - p) {
        nums += String(num, radix: n, uppercase: true).map { String($0) }
        num += 1
    }
    
    var index: Int = p - 1
    while answer.count < t {
        answer.append(nums[index])
        index += m
    }
    
    return answer.joined()
}