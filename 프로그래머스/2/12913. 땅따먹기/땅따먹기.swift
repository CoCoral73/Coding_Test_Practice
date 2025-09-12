import Foundation

func solution(_ land:[[Int]]) -> Int {
    var answer = 0
    let N = land.count
    
    var dp: [[Int]] = [[Int]](repeating: [0,0,0,0], count: N)
    dp[0] = land[0]

    for i in 1..<N {
        for j in 0..<4 {
            for k in 0..<4 {
                if j != k {
                    dp[i][j] = max(dp[i][j], land[i][j] + dp[i-1][k])
                }
            }
        }
    }

    return dp[N-1].max()!
}