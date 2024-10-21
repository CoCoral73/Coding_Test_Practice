import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var adj = [[Int]](repeating: [Int](), count: n+1)
    var visited = [Bool](repeating: false, count: n+1)
    wires.forEach { wire in
        adj[wire[0]].append(wire[1])
        adj[wire[1]].append(wire[0])
    }
    
    func dfs(_ now: Int, _ no_wire: Set<Int>) {
        visited[now] = true
        for i in adj[now] {
            if visited[i] { continue }
            if Set([now, i]) == no_wire { continue }
            dfs(i, no_wire)
        }
    }
    
    var result = n
    wires.forEach { wire in
        let no_wire = Set(wire)
        visited = [Bool](repeating: false, count: n+1)
        dfs(1, no_wire)
        let cnt1 = visited.filter { $0 == true }.count, cnt2 = n - cnt1
        //print(cnt1, cnt2)
        result = min(result, abs(cnt1-cnt2))
    }
    return result
}