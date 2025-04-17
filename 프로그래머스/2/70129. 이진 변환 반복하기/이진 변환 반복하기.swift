import Foundation

func solution(_ s:String) -> [Int] {
    func trans2Binary(_ s: inout String) -> Int {
        var result = s.count
        s = s.filter { $0 == "1" }
        result -= s.count
        
        s = String(s.count, radix: 2)
        return result
    }
    
    var s = s
    var answer: [Int] = [0, 0]
    while s != "1" {
        answer[0] += 1
        answer[1] += trans2Binary(&s)
    }
    
    return answer
}