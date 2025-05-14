import Foundation

func solution(_ citations:[Int]) -> Int {
    var (l, r) = (0, citations.max()!)
    var answer: Int = 0 
    
    while l <= r {
        let m = (l + r) / 2
        
        if citations.filter { $0 >= m }.count >= m {
            answer = max(answer, m)
            l = m + 1
        } else {
            r = m - 1
        }
    }
    return answer
}