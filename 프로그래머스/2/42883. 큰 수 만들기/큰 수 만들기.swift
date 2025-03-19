import Foundation

func solution(_ number:String, _ k:Int) -> String {
    let number = number.map { String($0) }
    var answer: [String] = []
    var startIndex = 0, endIndex = k
    
    while endIndex < number.count {
        var max = number[startIndex], index = startIndex
        for i in startIndex...endIndex {
            if number[i] > max {
                max = number[i]
                index = i
            }
            if max == "9" { break }
        }
        answer.append(max)
        startIndex = index + 1
        endIndex += 1
    }
    return answer.joined()
}