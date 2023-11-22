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

func solution(_ expressions:String) -> Int64 {
    var numbers = [Int64]()
    var operations = [Character]()
    
    var start = 0, end = 0
    while true {
        while end < expressions.count && expressions[end].isNumber { end += 1 }
        numbers.append(Int64(expressions[start..<end])!)
        if end == expressions.count { break }
        operations.append(expressions[end])
        start = end + 1
        end += 1
    }
    
    let set = Set(operations)
    var priority = [Character:Int](uniqueKeysWithValues: zip(set, [Int](repeating: 0, count: set.count)))
    var answer = Int64(0)
    
    func solve() {
        let oper = priority.keys.sorted(by: { priority[$0]! < priority[$1]! })
        var nums = numbers
        var opers = operations
        oper.forEach { op in
            var i = 0
            while i < opers.count {
                if op != opers[i] { i += 1; continue }
                if op == "+" {
                    nums[i] += nums[i+1]
                }
                else if op == "-" {
                    nums[i] -= nums[i+1]
                }
                else {
                    nums[i] *= nums[i+1]
                }
                nums.remove(at: i+1)
                opers.remove(at: i)
            }
        }
        
        let result = nums.first!
        answer = max(answer, result >= 0 ? result : -result)
    }
    
    func set_priority(_ depth:Int) {
        if depth == priority.count {
            solve()
            return
        }
        
        priority.keys.forEach {
            if priority[$0]! == 0 {
                priority[$0]! = depth + 1
                set_priority(depth+1)
                priority[$0]! = 0
            }
        }
    }

    set_priority(0)
    
    return answer
}