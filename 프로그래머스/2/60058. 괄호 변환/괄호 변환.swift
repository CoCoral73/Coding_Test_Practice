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


func solution(_ p:String) -> String {
    func rfunc(_ w:[String]) -> String {
        //Step 1
        if w.isEmpty { return "" }
        
        //Step 2
        var stack = [String](), cnt1 = 0, cnt2 = 0, index = 0
        for i in 0..<w.count {
            if w[i] == "(" { stack.append(w[i]); cnt1 += 1 }
            else { if !stack.isEmpty && stack.last! == "(" { stack.removeLast() }; cnt2 += 1 }
            if cnt1 == cnt2 { index = i; break }
        }
        var u = [String](w[0...index]), v = [String](w[(index+1)...])

        //Step 3
        if stack.isEmpty { return u.joined() + rfunc(v) }
        //Step 4
        else {
            u = u.suffix(u.count-1)
            u.removeLast()
            return "(" + rfunc(v) + ")" + u.map { $0 == "(" ? ")" : "(" }.joined()
        }
    }
    
    let w = p.map { String($0) }
    return rfunc(w)
}