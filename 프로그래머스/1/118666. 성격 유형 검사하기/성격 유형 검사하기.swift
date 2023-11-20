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

func solution(_ survey:[String], _ choices:[Int]) -> String {
    let type = ["RT", "CF", "JM", "AN"]
    var scores = Dictionary<Character, Int>(uniqueKeysWithValues: zip(type.joined(), [Int](repeating: 0, count: 8)))
    
    zip(survey, choices).forEach { (s, c) in
        let score = c - 4
        if score < 0 { scores[s[0]]! += abs(score) }
        else { scores[s[1]]! += score }
    }
    
    return type.reduce("") { $0 + String((scores[$1[0]]! >= scores[$1[1]]! ? $1[0] : $1[1])) }
}