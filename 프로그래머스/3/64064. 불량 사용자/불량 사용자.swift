import Foundation

extension String {
    subscript(_ i:Int) -> Character {
        let index = self.index(self.startIndex, offsetBy: i)
        return self[index]
    }
    subscript(_ range:Range<Int>) -> String {
        let start = self.index(self.startIndex, offsetBy: range.lowerBound)
        let end = self.index(self.startIndex, offsetBy: range.upperBound)
        return String(self[start..<end])
    }
    subscript(_ range:ClosedRange<Int>) -> String {
        let start = self.index(self.startIndex, offsetBy: range.lowerBound)
        let end = self.index(self.startIndex, offsetBy: range.upperBound)
        return String(self[start...end])
    }
}

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    var ban_user = [[Int]](repeating: [Int](), count: banned_id.count)
    var visited = [Bool](repeating: false, count: user_id.count)
    var check = Set<[Bool]>()
    var answer = 0
    
    banned_id.enumerated().forEach { ban in
        for i in 0..<user_id.count {
            if user_id[i].count != ban.element.count { continue }
            var flag = true
            for j in 0..<user_id[i].count {
                if ban.element[j] == "*" { continue }
                if ban.element[j] != user_id[i][j] { flag = false; break }
            }
            if flag { ban_user[ban.offset].append(i) }
        }
    }
    
    func dfs(_ depth:Int) {
        if depth == banned_id.count {
            if !check.contains(visited) {
                answer += 1
                check.insert(visited)
            }
            return
        }
        
        ban_user[depth].forEach { i in
            if !visited[i] {
                visited[i] = true
                dfs(depth+1)
                visited[i] = false
            }
        }
    }
    dfs(0)
    return answer
}