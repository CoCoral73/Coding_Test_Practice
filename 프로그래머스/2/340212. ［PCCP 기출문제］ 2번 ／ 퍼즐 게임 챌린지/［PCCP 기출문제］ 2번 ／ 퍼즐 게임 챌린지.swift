import Foundation

func solution(_ diffs:[Int], _ times:[Int], _ limit:Int64) -> Int {
    func simulate(level: Int) -> Int64 {
        var total: Int64 = 0 
        
        for i in 0..<diffs.count {
            if level >= diffs[i] {
                total += Int64(times[i])
            } else {
                total += Int64((diffs[i] - level) * (times[i] + times[i-1]) + times[i])
            }
        }
        
        return total 
    }
    
    var l = 1, r = diffs.max()!
    var answer = r
    
    while l <= r {
        let mid = (l + r) / 2
        
        if simulate(level: mid) <= limit {
            r = mid - 1
            answer = min(answer, mid)
        } else {
            l = mid + 1
        }
    }
    
    return answer
}