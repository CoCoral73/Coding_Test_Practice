import Foundation

func solution(_ myString:String) -> String {
    var answer = myString.lowercased()
    return answer.replacingOccurrences(of: "a", with: "A")
}