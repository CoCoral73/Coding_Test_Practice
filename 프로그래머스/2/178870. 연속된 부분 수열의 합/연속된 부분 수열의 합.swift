import Foundation

func solution(_ sequence:[Int], _ k:Int) -> [Int] {
    var l: Int = sequence.count-1, r: Int = sequence.count-1
    var sum: Int = sequence.last!, len: Int = 1000000
    var answer: [Int] = []
    
    while l >= 0 {
        if sum == k {
            if r-l+1 <= len {
                answer = [l, r]
                len = r-l+1
            }
            l -= 1
            if l >= 0 {
                sum += sequence[l]
            }
        } else if sum < k {
            l -= 1
            if l >= 0 {
                sum += sequence[l]
            }
        } else {
            sum -= sequence[r]
            if l == r {
                l -= 1
                if l >= 0 {
                    sum += sequence[l]
                }
                r -= 1
            } else {
                r -= 1
            }
        }
    }
    return answer
}