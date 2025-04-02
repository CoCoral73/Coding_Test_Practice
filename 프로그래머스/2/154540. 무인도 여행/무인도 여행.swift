import Foundation

func solution(_ maps:[String]) -> [Int] {
    let maps = maps.map { $0.map { String($0) } }
    let n = maps.count, m = maps[0].count
    var isVisited = [[Bool]](repeating: [Bool](repeating: false, count: m), count: n)
    var result: Int = 0, answer = [Int]()
    
    func dfs(_ r: Int, _ c: Int) {
        let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]
        
        isVisited[r][c] = true
        result += Int(maps[r][c])!
        
        for i in 0..<4 {
            let (newR, newC) = (r + dr[i], c + dc[i])
            if newR < 0 || newR >= n || newC < 0 || newC >= m { continue }
            if maps[newR][newC] == "X" || isVisited[newR][newC] { continue }
            
            isVisited[newR][newC] = true
            dfs(newR, newC)
        }
    }
    
    for i in 0..<n {
        for j in 0..<m {
            if maps[i][j] == "X" || isVisited[i][j] { continue }
            result = 0
            dfs(i, j)
            answer.append(result)
        }
    }
    
    if answer.isEmpty { answer = [-1] }
    return answer.sorted()
}