import Foundation

func solution(_ s:String) -> String {
    var answer = Array(s.lowercased()), index = 0
    for i in 0..<answer.count {
        if answer[i] == " " { index = 0 }
        else { answer[i] = index % 2 == 0 ? Character(answer[i].uppercased()) : answer[i]; index += 1 }
    }
    return String(answer)
}