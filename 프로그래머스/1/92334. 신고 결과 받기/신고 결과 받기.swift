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

struct info {
    var ids_reporting_me: Set<String>
    var mail:Int
    init() {
        ids_reporting_me = Set<String>()
        mail = 0
    }
}

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var dict = [String:info]()
    id_list.forEach { name in
        dict.updateValue(info(), forKey: name)
    }
    
    report.forEach {
        let names = $0.components(separatedBy: " ")
        let ing = names[0], ed = names[1]
        dict[ed]!.ids_reporting_me.insert(ing)
    }
    
    id_list.forEach { name in
        if dict[name]!.ids_reporting_me.count >= k {
            dict[name]!.ids_reporting_me.forEach {
                dict[$0]!.mail += 1
            }
        }
    }
    
    return id_list.map { dict[$0]!.mail }
}