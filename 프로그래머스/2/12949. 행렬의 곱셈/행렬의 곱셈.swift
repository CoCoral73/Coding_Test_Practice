import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    let (n, m, k) = (arr1.count, arr2[0].count, arr2.count)
    var answer = [[Int]](repeating: [Int](repeating: 0, count: m), count: n)
    
    for i in 0..<n {
        for j in 0..<m {
            //answer[i][j]
            for a in 0..<k {
                answer[i][j] += arr1[i][a] * arr2[a][j]
            }
        }
    }
    
    return answer
}