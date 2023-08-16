import Foundation

func solution(_ my_string:String) -> [String] {
    var answer = [String]()
    for i in 1...my_string.count {
        answer.append(String(my_string.suffix(i)))
    }
    answer.sort()
    return answer
}