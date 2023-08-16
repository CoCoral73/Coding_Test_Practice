import Foundation

func solution(_ intStrs:[String], _ k:Int, _ s:Int, _ l:Int) -> [Int] {
    var answer = [Int]()
    intStrs.forEach {
        let num = Int($0[$0.index($0.startIndex, offsetBy: s)..<$0.index($0.startIndex, offsetBy: s+l)])!
        if num > k { answer.append(num) }
    }
    return answer
}