import Foundation

func solution(_ s:String) -> [Int] {
    var s = s
    s.removeFirst(2)
    s.removeLast(2)
    
    let str = s.components(separatedBy: "},{").sorted(by: { $0.count < $1.count })
    var answer = [Int]()
    
    str.forEach {
        let nums = Set($0.components(separatedBy: ",").map { Int($0)! })
        let num = nums.subtracting(answer).first!
        answer.append(num)
    }
    
    return answer
}