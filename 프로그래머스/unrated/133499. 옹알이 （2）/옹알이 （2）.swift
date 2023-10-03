import Foundation

func solution(_ babbling:[String]) -> Int {
    var babbling = babbling
    var answer = babbling.count
    for i in 0..<babbling.count {
        babbling[i] = babbling[i].replacingOccurrences(of: "aya", with: "1")
        babbling[i] = babbling[i].replacingOccurrences(of: "ye", with: "2")
        babbling[i] = babbling[i].replacingOccurrences(of: "woo", with: "3")
        babbling[i] = babbling[i].replacingOccurrences(of: "ma", with: "4")
        if Int(babbling[i]) == nil { answer -= 1 }
        else if babbling[i].contains("11") { answer -= 1 }
        else if babbling[i].contains("22") { answer -= 1 }
        else if babbling[i].contains("33") { answer -= 1 }
        else if babbling[i].contains("44") { answer -= 1 }
    }
    return answer
}