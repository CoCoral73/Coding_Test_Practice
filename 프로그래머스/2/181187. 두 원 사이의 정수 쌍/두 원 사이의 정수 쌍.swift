import Foundation

func solution(_ r1:Int, _ r2:Int) -> Int64 {
    //x^2 + y^2 >= r1^2
    //x^2 + y^2 <= r2^2
    
    var answer: Int64 = 0
    for x in 0...r2 {
        if x <= r1 {
            var y1 = Int64(sqrt(Double(r1*r1 - x*x)))
            y1 = (y1*y1 == r1*r1 - x*x) ? y1 : y1 + 1
            let y2 = Int64(sqrt(Double(r2*r2 - x*x)))
            answer += (y2 - y1 + 1)
        } else {
            let y = Int64(sqrt(Double(r2*r2 - x*x)))
            answer += y + 1
        }
    }
    
    answer *= 4
    answer -= Int64(r2 - r1 + 1)*4
    return answer
}