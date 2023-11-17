import Foundation

func solution(_ s:String) -> [Int] {
    var arr = String(s[s.index(s.startIndex, offsetBy: 2)...s.index(s.endIndex, offsetBy: -3)]).split(separator: "}").map { $0.hasPrefix(",{") ? $0.suffix($0.count-2) : $0 }
    var answer = [Int]()
    arr.sort(by: { $0.count < $1.count })
    arr.forEach {
        let nums = $0.split(separator: ",").map { Int($0)! }
        let num = nums.filter { !answer.contains($0) }.first!
        answer.append(num)
    }
    return answer
}