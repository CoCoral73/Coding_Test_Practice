import Foundation

func solution(_ new_id:String) -> String {
    var answer = String(new_id)
    
    //step 1
    answer = answer.lowercased()
    //step 2
    answer.removeAll(where: { !$0.isLetter && !$0.isNumber && !"-_.".contains($0) })
    //step 3
    while answer.contains("..") { answer = answer.replacingOccurrences(of: "..", with: ".") }
    //step 4
    while answer.first == "." { answer.removeFirst() }
    while answer.last == "." { answer.removeLast() }
    //step 5
    if answer.count == 0 { answer = "a" }
    //step 6
    while answer.count >= 16 || answer.last == "." { answer.removeLast() }
    //step 7
    while answer.count <= 2 { answer.append(answer.last!) }
    return answer
}