import Foundation

func solution(_ k:Int, _ ranges:[[Int]]) -> [Double] {
    var arr: [Int] = [k], psum: [Double] = [0]
    var answer: [Double] = []
    
    while arr.last! != 1 {
        let a = arr.last!
        var b = a
        
        if a % 2 == 0 { b /= 2 }
        else { b = b * 3 + 1 }
        arr.append(b)
        psum.append(psum.last! + Double(a+b)/2.0)
    }

    let n = arr.count - 1
    for range in ranges {
        var (a, b) = (range[0], range[1] + n)
        
        if a > b {
            answer.append(-1)
        } else {
            answer.append(psum[b] - psum[a])
        }
    }
    
    return answer
}