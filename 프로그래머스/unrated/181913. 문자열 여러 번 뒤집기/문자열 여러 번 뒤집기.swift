import Foundation

func solution(_ my_string:String, _ queries:[[Int]]) -> String {
    var answer = String(my_string)
    queries.forEach {
        let s = answer.index(answer.startIndex, offsetBy: $0[0])
        let e = answer.index(answer.startIndex, offsetBy: $0[1])
        answer.replaceSubrange(s...e, with: answer[s...e].reversed())
    }
    return answer
}