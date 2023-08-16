import Foundation

func solution(_ my_string:String, _ s:Int, _ e:Int) -> String {
    var answer = String(my_string)
    let s = answer.index(answer.startIndex, offsetBy: s)
    let e = answer.index(answer.startIndex, offsetBy: e)
    let rev = String(answer[s...e].reversed())
    answer.replaceSubrange(s...e, with: rev)
    return answer
}