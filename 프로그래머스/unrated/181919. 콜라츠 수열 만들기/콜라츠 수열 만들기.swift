import Foundation

func solution(_ n:Int) -> [Int] {
    var answer = [Int]()
    answer.append(n)
    while (true) {
        let last = answer.last!
        if last % 2 == 0 { answer.append(last / 2) }
        else { answer.append(last * 3 + 1) }
        if (answer.last! == 1) { break }
    }
    return answer
}