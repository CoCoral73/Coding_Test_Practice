import Foundation

func solution(_ t:String, _ p:String) -> Int {
    var answer = 0
    for i in 0...t.count-p.count {
        if t[t.index(t.startIndex, offsetBy: i)..<t.index(t.startIndex, offsetBy: i+p.count)] <= p { answer += 1 }
    }
    return answer
}