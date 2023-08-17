import Foundation

func solution(_ my_string:String, _ indices:[Int]) -> String {
    var answer = Array(my_string)
    indices.forEach { answer[$0] = " " }
    return String(answer).replacingOccurrences(of: " ", with: "")
}