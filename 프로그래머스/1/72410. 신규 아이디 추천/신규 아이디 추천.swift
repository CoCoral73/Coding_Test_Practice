import Foundation

func solution(_ new_id:String) -> String {
    var answer = new_id
    
    answer = answer.lowercased()
    answer = answer.filter { $0.isLowercase || $0.isNumber || $0 == "-" || $0 == "_" || $0 == "." }
    while answer.contains("..")  {
        answer = answer.replacingOccurrences(of: "..", with: ".")
    }
    while !answer.isEmpty && answer.first! == "." { answer.removeFirst() }
    while !answer.isEmpty && answer.last! == "." { answer.removeLast() }
    if answer.isEmpty { answer = "a" }
    answer = String(answer.prefix(15))
    while !answer.isEmpty && answer.last! == "." { answer.removeLast() }
    while answer.count <= 2 { answer.append(answer.last!) }
    
    return answer
}