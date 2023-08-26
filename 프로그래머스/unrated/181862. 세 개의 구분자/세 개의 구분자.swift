import Foundation

func solution(_ myStr:String) -> [String] {
    var answer = myStr.components(separatedBy: ["a", "b", "c"]).filter { $0.count > 0 }
    if answer.count == 0 { answer.append("EMPTY") }
    return answer
}