import Foundation

func solution(_ number:String, _ k:Int) -> String {
    let number = number.map { String($0) }
    var answer: [String] = []
    
    var left: Int = 0, right: Int = k
    while answer.count < number.count - k {
        var max = number[left], index = left
        for i in stride(from: left, through: right, by: 1) {
            if max < number[i] {
                max = number[i]
                index = i
            }
            if max == "9" { break }
        }
        
        answer.append(max)
        left = index + 1
        right = min(right + 1, number.count - 1)
    }
    
    return answer.joined()
}