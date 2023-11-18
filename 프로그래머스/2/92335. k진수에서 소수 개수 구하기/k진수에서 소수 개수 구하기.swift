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
}
extension Int {
    func isPrime() -> Bool {
        if self < 2 { return false }
        if self < 4 { return true }
        for i in 2...Int(sqrt(Double(self))) {
            if self % i == 0 { return false }
        }
        return true
    }
}

func solution(_ n:Int, _ k:Int) -> Int {
    let binary = String(n, radix: k)
    var start = 0, end = 0, answer = 0
    
    while binary.getCharacter(start) == "0" { start += 1 }
    while start < binary.count {
        end = start
        while end < binary.count && binary.getCharacter(end) != "0" { end += 1 }
        
        if Int(binary.substring(start..<end))!.isPrime() { answer += 1 }
        start = end + 1
        while start < binary.count && binary.getCharacter(start) == "0" { start += 1 }
    }
    return answer
}