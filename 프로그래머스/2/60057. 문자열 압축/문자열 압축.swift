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

func solution(_ s:String) -> Int {
    func slicing(_ len:Int) -> [String] {
        var start = 0
        var arr = [String]()
        while start < s.count {
            if start + len <= s.count { arr.append(s[start..<(start+len)]) }
            else { arr.append(s[start..<s.count]) }
            start += len
        }
        return arr
    }
    
    var answer = s.count, i = 1
    
    while i <= s.count / 2 {
        let slices = slicing(i)
        var result = [String]()
        var start = 0, end = 0
        while start < slices.count {
            while end < slices.count && slices[start] == slices[end] { end += 1 }
            if end - start > 1 { result.append(String(end-start)) }
            result.append(slices[start])
            start = end
        }
        answer = min(answer, result.joined().count)
        i += 1
    }
    return answer
}