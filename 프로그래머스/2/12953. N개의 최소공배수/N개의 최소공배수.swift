import Foundation

func getGCD(_ a: Int, _ b: Int) -> Int {
    return b == 0 ? a : getGCD(b, a % b)
}

func solution(_ arr:[Int]) -> Int {
    var arr = arr
    
    while arr.count > 1 {
        let a = arr.removeLast(), b = arr.removeLast()
        let gcd = getGCD(a, b)
        arr.append((a * b) / gcd)
    }
    
    return arr.last!
}