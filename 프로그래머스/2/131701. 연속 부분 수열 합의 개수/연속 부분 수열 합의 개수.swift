import Foundation

func solution(_ elements:[Int]) -> Int {
    var answer: Set<Int> = []
    
    for i in 0..<elements.count {
        var sum: Int = 0
        for j in i..<(i+elements.count) {
            let index = j % elements.count
            sum += elements[index]
            answer.insert(sum)
        }
    }
    return answer.count
}