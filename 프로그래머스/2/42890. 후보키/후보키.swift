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

func solution(_ relation:[[String]]) -> Int {
    let row = relation.count, column = relation[0].count
    var answer = 0
    
    var Included = Set<Set<Int>>()
    var isSelected = [Bool](repeating: false, count: column)
    func makeTuple(_ line:[String]) -> [String] {
        var tuple = [String]()
        for i in 0..<column {
            if !isSelected[i] { continue }
            tuple.append(line[i])
        }
        return tuple
    }
    
    func dfs(_ depth:Int, _ size:Int) {
        if depth == size {
            var check = Set<[String]>()
            for i in 0..<row { check.insert(makeTuple(relation[i])) }
            if check.count == row {
                let combination = Set(isSelected.enumerated().filter { $0.element == true }.map { $0.offset })
                var flag = true
                Included.forEach {
                    if $0.isSubset(of: combination) { flag = false }
                }
                if flag { answer += 1; Included.insert(combination) }
            }
            return
        }
        
        for i in 0..<column {
            if isSelected[i] { continue }
            isSelected[i] = true
            dfs(depth+1, size)
            isSelected[i] = false
        }
    }
    
    for i in 1...column {
        dfs(0, i)
    }

    return answer
}