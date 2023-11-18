import Foundation

extension String {
    func getCharacter(_ i:Int) -> Character {
        let index = self.index(self.startIndex, offsetBy: i)
        return self[index]
    }
    func substring(_ range: Range<Int>) -> String {
        let start = self.index(self.startIndex, offsetBy: range.lowerBound)
        let end = self.index(self.startIndex, offsetBy: range.upperBound)
        return String(self[start..<end])
    }
    func substring(_ closedrange: ClosedRange<Int>) -> String {
        let start = self.index(self.startIndex, offsetBy: closedrange.lowerBound)
        let end = self.index(self.startIndex, offsetBy: closedrange.upperBound)
        return String(self[start...end])
    }
}


func solution(_ msg:String) -> [Int] {
    var dict = Dictionary<String, Int>(), last = 27
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ".enumerated().forEach { dict.updateValue($0.offset+1, forKey: String($0.element)) }
    
    var answer = [Int]()
    var start = 0, end = 0
    while start < msg.count {
        end = start
        while end < msg.count && dict[msg.substring(start...end)] != nil { end += 1 }
        answer.append(dict[msg.substring(start..<end)]!)
        if end < msg.count { dict.updateValue(last, forKey: msg.substring(start...end)); last += 1 }
        start = end
    }
    return answer
}
