import Foundation

func solution(_ s:String) -> String {
    let nums = s.components(separatedBy: " ").map{ Int($0)! }
    let MIN = nums.min()!, MAX = nums.max()!
    return "\(MIN) \(MAX)"
}