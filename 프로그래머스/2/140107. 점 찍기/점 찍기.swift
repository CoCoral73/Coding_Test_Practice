import Foundation

func solution(_ k:Int, _ d:Int) -> Int64 {
    var answer: Int64 = 0
    
    for x in stride(from: 0, through: d, by: k) {
        let yy = d*d - x*x, y = Int(sqrt(Double(yy)))

        answer += Int64(y/k) + 1
    }
    
    return answer
}