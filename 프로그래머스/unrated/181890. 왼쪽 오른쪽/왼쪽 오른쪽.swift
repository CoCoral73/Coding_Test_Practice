import Foundation

func solution(_ str_list:[String]) -> [String] {
    var answer = [String]()
    let left = str_list.firstIndex(of: "l") ?? 0
    let right = str_list.firstIndex(of: "r") ?? str_list.endIndex
    answer.append(contentsOf: left < right ? str_list[..<left] : str_list[(right+1)...])
    return answer
}