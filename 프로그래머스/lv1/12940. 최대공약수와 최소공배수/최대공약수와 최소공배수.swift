import Foundation

func solution(_ n:Int, _ m:Int) -> [Int] {
    func GCD(_ a:Int, _ b:Int) -> Int {
        return b == 0 ? a : GCD(b, a%b)
    }
    let gcd = GCD(max(n, m), min(n, m))
    return [gcd, n*m / gcd]
}