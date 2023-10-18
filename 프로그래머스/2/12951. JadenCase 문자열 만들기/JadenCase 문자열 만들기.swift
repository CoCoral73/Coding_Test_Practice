import Foundation

func solution(_ s:String) -> String {
    let s = Array(s.lowercased())
    let answer: [String]
    answer = s.enumerated().map {
        if $0.offset == 0 || s[$0.offset-1] == " " { return String($0.element).uppercased() }
        else { return String($0.element) }
    }
    return answer.joined()
}
