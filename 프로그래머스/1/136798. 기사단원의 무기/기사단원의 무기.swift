import Foundation

func solution(_ number:Int, _ limit:Int, _ power:Int) -> Int {
    func sol(_ n:Int) -> Int {
        var answer = 0, index = 1
        while index * index <= n {
            if index * index == n { answer += 1 }
            else if (n % index == 0 ) { answer += 2 }
            if answer > limit { return power }
            index += 1
        }
        return answer
    }
    return (1...number).map { sol($0) }.reduce(0, +)
}