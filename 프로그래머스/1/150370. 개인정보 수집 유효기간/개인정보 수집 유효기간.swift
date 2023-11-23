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

func solution(_ today:String, _ terms:[String], _ privacies:[String]) -> [Int] {
    func convertDay(_ ymd:[String]) -> Int {
        return Int(ymd[0])!*12*28 + Int(ymd[1])!*28 + Int(ymd[2])!
    }
    
    var today = convertDay(today.components(separatedBy: "."))
    var dict = [String:Int]()
    terms.forEach {
        let term = $0.components(separatedBy: " ")
        dict.updateValue(Int(term[1])!, forKey: term[0])
    }
    
    var answer = [Int]()
    privacies.enumerated().forEach {
        let privacy = $0.element.components(separatedBy: " ")
        let days = convertDay(privacy[0].components(separatedBy: "."))
        let term = dict[privacy[1]]! * 28
        
        if days + term - 1 < today { answer.append($0.offset + 1) }
    }
    return answer
}