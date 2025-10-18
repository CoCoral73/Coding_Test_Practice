import Foundation

func convertToMinute(_ s: String) -> Int {
    let time = s.components(separatedBy: ":").map { Int($0)! }
    return time[0] * 60 + time[1]
}

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var inTimeByCarNumber: [String: Int] = [:]
    var accumulatedTimeByCarNumber: [String: Int] = [:]
    var answer: [Int] = []
    
    for record in records {
        let r = record.components(separatedBy: " ")
        let time = convertToMinute(r[0])
        
        if r[2] == "IN" {
            inTimeByCarNumber[r[1]] = time
        } else {
            let accumulated = time - inTimeByCarNumber[r[1]]!
            accumulatedTimeByCarNumber[r[1], default: 0] += accumulated
            inTimeByCarNumber.removeValue(forKey: r[1])
        }
    }
    
    for (car, time) in inTimeByCarNumber {
        let accumulated = 1439 - time
        accumulatedTimeByCarNumber[car, default: 0] += accumulated
    }
    
    answer = accumulatedTimeByCarNumber.sorted(by: { $0.key < $1.key }).map {
        var result: Int = fees[1]
        let time: Int = max($0.value - fees[0], 0)
        
        result += ((time % fees[2] == 0 ? 0 : 1) + time / fees[2]) * fees[3] 
        return result
    }
    
    return answer
}