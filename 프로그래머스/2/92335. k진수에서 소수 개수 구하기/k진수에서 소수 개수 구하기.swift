import Foundation

func isPrime(_ n: Int) -> Bool {
    if n <= 1 { return false }
    if n <= 3 { return true }
    
    for i in stride(from: 2, through: Int(pow(Double(n), 0.5)), by: 1) {
        if n % i == 0 { return false }
    }
    return true 
}

func solution(_ n:Int, _ k:Int) -> Int {
    var nums = String(n, radix: k).components(separatedBy: "0").filter { $0 != "" }
    var answer: Int = 0
    
    for num in nums {
        if isPrime(Int(num)!) {
            answer += 1
        }
    }
    return answer
}