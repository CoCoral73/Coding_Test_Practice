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

func solution(_ gems:[String]) -> [Int] {
    let type = Set(gems)
    var gem_count = Dictionary<String, Int>()
    var start = 0, end = start, MIN = gems.count + 1
    var s = start, e = end
    
    gem_count[gems[start]] = 1
    while end < gems.count && start <= end {
        if gem_count.count == type.count {
            if end - start + 1 < MIN { s = start; e = end; MIN = end - start + 1 }
            if start - end + 1 == type.count { break }
            gem_count[gems[start]]! -= 1
            if gem_count[gems[start]] == 0 { gem_count.removeValue(forKey: gems[start]) }
            start += 1
        }
        else {
            end += 1
            if end < gems.count {
                if gem_count[gems[end]] == nil { gem_count.updateValue(1, forKey: gems[end])}
                else { gem_count[gems[end]]! += 1 }
            }
        }
        
        if gems.count - start < type.count { break }
    }
    
    return [s+1, e+1]
}