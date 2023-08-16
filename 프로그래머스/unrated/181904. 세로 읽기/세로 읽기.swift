import Foundation

func solution(_ my_string:String, _ m:Int, _ c:Int) -> String {
    var answer = String()
    for i in 0..<(my_string.count / m) {
        let index = my_string.index(my_string.startIndex, offsetBy: i*m+c-1)
        answer.append(my_string[index])
    }
    return answer
}