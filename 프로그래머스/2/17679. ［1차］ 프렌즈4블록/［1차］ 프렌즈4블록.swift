func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    var board = board.map { Array($0).map { String($0) } }
    var visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
    var answer: Int = 0
    
    func check(_ i: Int, _ j: Int) -> Int {
        if board[i][j] == "" { return 0 }
        if i + 1 >= m || j + 1 >= n { return 0 }
        
        let (d1, d2, d3, d4) = (board[i][j], board[i][j+1], board[i+1][j], board[i+1][j+1])
        if !(d1 == d2 && d1 == d3 && d1 == d4) { return 0 }
        
        var result: Int = 0
        result += (visited[i][j] ? 0 : 1)
        result += (visited[i][j+1] ? 0 : 1)
        result += (visited[i+1][j] ? 0 : 1)
        result += (visited[i+1][j+1] ? 0 : 1)
        
        visited[i][j] = true
        visited[i][j+1] = true
        visited[i+1][j] = true
        visited[i+1][j+1] = true
        
        return result
    }
    
    func clear() {
        for i in 0..<m {
            for j in 0..<n {
                if visited[i][j] { board[i][j] = "" }
            }
        }
    }
    
    func move() {
        for j in 0..<n {
            for i in stride(from: m-1, through: 1, by: -1) {
                if board[i][j] == "" {
                    let k = stride(from: i-1, through: 0, by: -1).first { board[$0][j] != "" }
                    if k == nil { break }
                    board[i][j] = board[k!][j]
                    board[k!][j] = ""
                }
            }
        }
    }
    
    while true {
        var flag: Int = 0
        for i in 0..<m {
            for j in 0..<n {
                flag += check(i, j)
            }
        }
        
        if flag == 0 { break }
        answer += flag
        
        clear()
        move()
        visited = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
    }
    
    return answer

}