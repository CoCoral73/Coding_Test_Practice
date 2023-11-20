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

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    var combination = [Dictionary<String, Int>](repeating: Dictionary<String, Int>(), count: course.count)
    
    var comb = [String]()
    func dfs(_ now:Int, _ course_index:Int, _ start:Int, _ orders_index:Int) {
        if now == course[course_index] {
            let str = comb.sorted().joined()
            if combination[course_index][str] == nil {
                combination[course_index].updateValue(1, forKey: str)
                for i in (orders_index+1)..<orders.count {
                    if Set(str).isSubset(of: orders[i]) { combination[course_index][str]! += 1 }
                }
            }
            return
        }
        
        for i in start..<orders[orders_index].count {
            comb.append(String(orders[orders_index][i]))
            dfs(now+1, course_index, i+1, orders_index)
            comb.removeLast()
        }
    }
    
    for i in 0..<course.count {
        for j in 0..<orders.count {
            dfs(0, i, 0, j)
        }
    }
    
    let MAX = combination.map { $0.values.max() ?? 0 }
    let answer = combination.enumerated().map { c in
        c.element.keys.filter { MAX[c.offset] >= 2 && combination[c.offset][$0]! == MAX[c.offset] }
    }
    
    return answer.reduce([]) { $0 + $1 }.sorted()
}