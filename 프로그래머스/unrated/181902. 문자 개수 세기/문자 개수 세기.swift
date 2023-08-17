import Foundation

func solution(_ my_string:String) -> [Int] {
    var answer = Array(repeating: 0, count: 52)
    my_string.forEach {
        if $0.isUppercase { answer[Int($0.asciiValue!)-65] += 1 }
        else { answer[Int($0.asciiValue!)-97+26] += 1}
    }
    return answer
}