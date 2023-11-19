import Foundation

func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    var board = board.map { Array($0) }
    var answer = 0
    
    while true {
        var visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
        var remove = false
        for i in 0..<(m-1) {
            for j in 0..<(n-1) {
                if board[i][j] != "0" && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1] {
                    answer = visited[i][j] ? answer : answer + 1; visited[i][j] = true
                    answer = visited[i][j+1] ? answer : answer + 1; visited[i][j+1] = true
                    answer = visited[i+1][j] ? answer : answer + 1; visited[i+1][j] = true
                    answer = visited[i+1][j+1] ? answer : answer + 1; visited[i+1][j+1] = true
                    remove = true
                }
            }
        }
        if !remove { break }
        
        for i in 0..<m {
            for j in 0..<n {
                if visited[i][j] { board[i][j] = "0" }
            }
        }

        for c in 0..<n {
            var a = m - 1, b: Int
            while a >= 0 && board[a][c] != "0" { a -= 1 }
            if a < 0 { continue }
            b = a
            while b >= 0 {
                while b >= 0 && board[b][c] == "0" { b -= 1 }
                if b < 0 { break }
                while b >= 0 && board[b][c] != "0" { board[a][c] = board[b][c]; board[b][c] = "0"; a -= 1; b -= 1 }
            }
        }
    }
    return answer
}