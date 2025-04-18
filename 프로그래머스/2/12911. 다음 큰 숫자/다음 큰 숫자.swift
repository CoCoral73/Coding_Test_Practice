import Foundation

func solution(_ n: Int) -> Int {
    var answer: Int = n + 1
    let countOf1 = String(n, radix: 2).filter { $0 == "1" }.count
    
    while String(answer, radix: 2).filter { $0 == "1" }.count != countOf1 {
        answer += 1
    }
    
    return answer
}