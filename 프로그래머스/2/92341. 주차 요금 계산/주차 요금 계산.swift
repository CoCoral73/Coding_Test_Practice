import Foundation

extension String {
    func substring(_ range:ClosedRange<Int>) -> String {
        let start = self.index(self.startIndex, offsetBy: range.lowerBound)
        let end = self.index(self.startIndex, offsetBy: range.upperBound)
        return String(self[start...end])
    }
}

func solution(_ fees: [Int], _ records: [String]) -> [Int] {
    var INOUT = Dictionary<String, (In: Int, Time: Int)>()
    var COST = Dictionary<String, Int>()
    
    records.forEach { record in
        let T = Int(record.substring(0...1))! * 60 + Int(record.substring(3...4))!
        let car = record.substring(6...9)
        if record.count == 13 {
            if INOUT[car] == nil { INOUT.updateValue((In: T, Time: 0), forKey: car) }
            else {
                INOUT[car]!.In = T
            }
            COST.updateValue(0, forKey: car)
        }
        else {
            let time = T - INOUT[car]!.In
            INOUT[car]!.Time += time
            INOUT[car]!.In = -1
        }
    }

    INOUT.forEach { (key, value) in
        if value.In != -1 { INOUT[key]!.Time += 23*60 + 59 - value.In }
        COST[key]! += fees[1]
        let plus = INOUT[key]!.Time - fees[0]
        if plus > 0 {
            let unit_plus = (plus % fees[2]) == 0 ? plus / fees[2] : plus / fees[2] + 1
            COST[key]! += fees[3] * unit_plus
        }
    }
    
    return COST.keys.sorted().map { COST[$0]! }
}