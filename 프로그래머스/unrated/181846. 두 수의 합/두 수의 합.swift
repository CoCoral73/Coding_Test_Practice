import Foundation

func solution(_ a:String, _ b:String) -> String {
    var a = a.map { String($0) }, b = b.map { String($0) }
    var answer = ""
    var flag = 0
    while !a.isEmpty && !b.isEmpty {
        let plus = Int(a.removeLast())! + Int(b.removeLast())! + flag
        answer.append(String(plus % 10))
        flag = plus / 10
    }
    while !a.isEmpty {
        let A = Int(a.removeLast())! + flag
        answer.append(String(A % 10))
        flag = A / 10
    }
    while !b.isEmpty {
        let B = Int(b.removeLast())! + flag
        answer.append(String(B % 10))
        flag = B / 10
    }
    if flag == 1 { answer.append("1") }
    return String(answer.reversed())
}