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


func solution(_ m:String, _ musicinfos:[String]) -> String {
    var answer:String?, max_time:Int?
    
    for i in 0..<musicinfos.count {
        let infos = musicinfos[i].components(separatedBy: ",")
        let start = Int(infos[0][0...1])! * 60 + Int(infos[0][3...4])!
        let end   = Int(infos[1][0...1])! * 60 + Int(infos[1][3...4])!
        
        var neo = [String](), index = 0
        while index < m.count {
            let next = index + 1
            if next < m.count && m[next] == "#" {
                neo.append(m[index...next])
                index += 2
            }
            else { neo.append(String(m[index])); index = next }
        }

        if end - start < neo.count { continue }
        
        var melody = [String](), time = 0
        index = 0
        while time < end - start {
            let next = (index + 1) % infos[3].count
            if infos[3][next] == "#" { melody.append(infos[3][index...next]); index = (index + 2) % infos[3].count }
            else { melody.append(String(infos[3][index])); index = next}
            time += 1
        }

        for a in 0...melody.count-neo.count {
            var flag = true
            for b in 0..<neo.count {
                if melody[a + b] != neo[b] { flag = false; break }
            }
            if flag {
                if max_time == nil { answer = infos[2]; max_time = end - start }
                else if end - start > max_time! { answer = infos[2]; max_time = end - start }
            }
        }
    }
    return answer ?? "(None)"
}