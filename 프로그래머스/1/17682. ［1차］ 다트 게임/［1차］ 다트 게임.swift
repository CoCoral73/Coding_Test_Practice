import Foundation

extension String {
    func getChar(_ i:Int) -> Character {
        let index = self.index(self.startIndex, offsetBy: i)
        return self[index]
    }
    func substring(_ range: Range<Int>) -> String {
        let start = self.index(self.startIndex, offsetBy: range.lowerBound)
        let end = self.index(self.startIndex, offsetBy: range.upperBound)
        return String(self[start..<end])
    }
}
func solution(_ dartResult:String) -> Int {
    func getScore(_ score:Int, bonus:Character) -> Int {
        switch bonus {
        case "S": return score
        case "D": return score*score
        default: return score*score*score
        }
    }
    
    var start = 0, end = 0
    var answer = [Int](), last = -1
    while start < dartResult.count {
        end = start
        while dartResult.getChar(end).isNumber { end += 1 }
        let score = getScore(Int(dartResult.substring(start..<end))!, bonus: dartResult.getChar(end))
        answer.append(score); last += 1
        if end+1 < dartResult.count && !dartResult.getChar(end+1).isNumber {
            end += 1
            if dartResult.getChar(end) == "*" {
                answer[last] *= 2;
                if last - 1 >= 0 { answer[last-1] *= 2 }
            }
            else { answer[last] *= -1 }
        }
        start = end + 1
    }
    return answer.reduce(0, +)
}