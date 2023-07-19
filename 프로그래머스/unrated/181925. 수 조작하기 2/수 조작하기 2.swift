import Foundation

func solution(_ numLog:[Int]) -> String {
    var answer = String()
    for idx in 0..<numLog.count-1 {
        switch numLog[idx+1]-numLog[idx] {
        case 1:
            answer.append("w")
            break
        case -1:
            answer.append("s")
            break
        case 10:
            answer.append("d")
            break
        default:
            answer.append("a")
        }
    }
    return answer
}