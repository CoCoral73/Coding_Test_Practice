import Foundation

func solution(_ my_strings:[String], _ parts:[[Int]]) -> String {
    var answer = String()
    for i in 0..<parts.count {
        let s = my_strings[i].index(my_strings[i].startIndex, offsetBy: parts[i][0])
        let e = my_strings[i].index(my_strings[i].startIndex, offsetBy: parts[i][1])
        answer += my_strings[i][s...e]
    }
    return answer
}