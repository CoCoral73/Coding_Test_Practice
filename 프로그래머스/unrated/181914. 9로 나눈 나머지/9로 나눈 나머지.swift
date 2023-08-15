import Foundation

func solution(_ number:String) -> Int {
    var answer = 0
    number.forEach {
        answer = (answer + Int(String($0))!) % 9
    }
    return answer
}