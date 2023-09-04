import Foundation

func solution(_ n:Int) -> [[Int]] {
    let dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    var answer = [[Int]](repeating: [Int](repeating: 0, count: n), count: n)
    var r = 0, c = -1, d = 0
    
    for i in 1...n*n {
        if r + dir[d][0] < 0 || r + dir[d][0] >= n || c + dir[d][1] < 0 || c + dir[d][1] >= n { d = (d + 1) % 4 }
        if answer[r + dir[d][0]][c + dir[d][1]] != 0 { d = (d + 1) % 4 }
        r += dir[d][0]
        c += dir[d][1]
        answer[r][c] = i
    }
    return answer
}