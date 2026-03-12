import Foundation

func solution(_ places:[[String]]) -> [Int] {
    var answer: [Int] = []
    
    for place in places {
        let array = place.map { str in return str.map { return String($0) }}
        var isVisited = [[Bool]](repeating: [Bool](repeating: false, count: 5), count: 5)
        
        func dfs(_ depth: Int, _ r: Int, _ c: Int) -> Bool {
            isVisited[r][c] = true
            
            if (depth == 2) {
                return false
            }
            
            let dr = [-1, 0, 1, 0]
            let dc = [0, 1, 0, -1]
            
            for i in 0..<4 {
                let newR = r + dr[i]
                let newC = c + dc[i]
                
                if newR < 0 || newR >= 5 || newC < 0 || newC >= 5 { continue }
                if isVisited[newR][newC] { continue }
                if array[newR][newC] == "X" { continue }
                if array[newR][newC] == "P" { return true }
                
                let flag = dfs(depth + 1, newR, newC)
                if flag { return true }
            }
            return false
        }
        
        var flag = false
        for i in 0..<5 {
            for j in 0..<5 {
                if array[i][j] == "P" {
                    flag = dfs(0, i, j)
                    if flag { break }
                }
            }
            if flag { break }
        }
        
        answer.append(flag ? 0 : 1)
    }
    
    return answer
}