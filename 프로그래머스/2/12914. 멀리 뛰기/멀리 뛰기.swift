import Foundation

func solution(_ n:Int) -> Int {
    if n == 1 { return 1 }
    var dp = [Int](repeating: 0, count: n+1)
    dp[0] = 0
    dp[1] = 1
    dp[2] = 2
    for i in 3..<(n+1) { dp[i] = (dp[i-2] + dp[i-1]) % 1234567 }
    return dp[n]
}