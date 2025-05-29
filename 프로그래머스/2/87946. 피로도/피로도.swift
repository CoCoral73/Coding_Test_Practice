import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var isVisited = [Bool](repeating: false, count: dungeons.count)
    var answer: Int = 0
    
    func dfs(_ depth: Int, _ state: Int) {
        answer = max(answer, depth)
        if depth == dungeons.count {
            return 
        }    
        
        for i in 0..<dungeons.count {
            if isVisited[i] { continue }
            if dungeons[i][0] > state { continue }
            isVisited[i] = true
            dfs(depth + 1, state - dungeons[i][1])
            isVisited[i] = false 
        }
    }
    
    dfs(0, k)
    return answer
}