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

func solution(_ places:[[String]]) -> [Int] {
    var visited = [[Bool]](repeating: [Bool](repeating: false, count: 5), count: 5)
    var answer = [Int](repeating: 1, count: 5)
    let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]
    var flag = true
    
    
    places.enumerated().forEach {
        let place = $0.element
        flag = true 
        for i in 0..<5 {
            for j in 0..<5 {
                if place[i][j] != "P" { continue }
                visited[i][j] = true
                for a in 0..<4 {
                    let r1 = i + dr[a], c1 = j + dc[a]
                    if r1 < 0 || r1 >= 5 || c1 < 0 || c1 >= 5 { continue }
                    if place[r1][c1] == "P" { flag = false; break }
                    if place[r1][c1] == "X" { continue }
                    visited[r1][c1] = true
                    for b in 0..<4 {
                        let r2 = r1 + dr[b], c2 = c1 + dc[b]
                        if r2 < 0 || r2 >= 5 || c2 < 0 || c2 >= 5 { continue }
                        if visited[r2][c2] { continue }
                        if place[r2][c2] == "P" { flag = false; break }
                    }
                    visited[r1][c1] = false
                    if !flag { break }
                }
                visited[i][j] = false
                if !flag { break }
            }
            if !flag { answer[$0.offset] = 0 }
        }
    }

    return answer
}