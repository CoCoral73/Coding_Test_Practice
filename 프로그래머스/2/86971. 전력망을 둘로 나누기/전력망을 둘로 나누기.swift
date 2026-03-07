import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var isVisited = [Bool](repeating: false, count: n+1)
    var edges = [[Int]](repeating: [Int](), count: n+1)
    var cutLine: [Int] = []
    var result: Int = 0, answer: Int = 100
    
    func dfs(_ a: Int) {
        isVisited[a] = true
        result += 1
        
        for b in edges[a] {
            if !isVisited[b] && (cutLine != [a, b] && cutLine != [b, a]) {
                dfs(b)
            }
        }
    }
    
    for wire in wires {
        let (a, b) = (wire[0], wire[1])
        edges[a].append(b)
        edges[b].append(a)
    }
    
    for wire in wires {
        result = 0
        (1...n).forEach { isVisited[$0] = false }
        cutLine = wire
        dfs(1)
        answer = min(answer, abs(n - 2 * result))
    }
    
    return answer
}