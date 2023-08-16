import Foundation

func solution(_ q:Int, _ r:Int, _ code:String) -> String {
    var code_index = [Int]()
    var answer = String()
    for i in 0..<code.count { code_index.append(i % q) }
    for i in 0..<code.count {
        if code_index[i] == r { answer.append(code[code.index(code.startIndex, offsetBy: i)]) }
    }
    return answer
}