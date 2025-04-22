import Foundation

func solution(_ n:Int) -> Int {
    var dp: [Int] = [0, 1, 2]
    
    for i in stride(from: 3, through: n, by: 1) {
        dp.append((dp[i-2]+dp[i-1]) % 1234567)
    }
    
    return dp[n]
}

/*
n: 1 -> 1
n: 2 -> 2
n: 3 -> 3
n: 4 -> 5
*/