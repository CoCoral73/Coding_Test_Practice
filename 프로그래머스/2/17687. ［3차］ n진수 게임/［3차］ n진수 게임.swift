import Foundation

extension String {
    func getChar(_ i:Int) -> Character {
        let index = self.index(self.startIndex, offsetBy: i)
        return self[index]
    }
}

func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    var answer = [String]()
    var num = 0, order = 0
    
    while true {
        let converted = String(num, radix: n, uppercase: true)
        for i in 0..<converted.count {
            if order == p-1 { answer.append(String(converted.getChar(i))) }
            if answer.count == t { return answer.joined() }
            order = (order + 1) % m
        }
        num += 1
    }
    return answer.joined()
}