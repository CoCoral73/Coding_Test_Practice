import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var results: [Int] = []
    var answer: [Int] = [] 
    
    results = zip(progresses, speeds).map { (p, s) in 
        if (100-p) % s == 0 {
            return (100-p) / s
        } else {
            return (100-p) / s + 1
        }
    }
    
    var idx1: Int = 0, idx2 = idx1 + 1
    while idx1 < results.count {
        while idx2 < results.count && results[idx1] >= results[idx2] {
            idx2 += 1
        }
        answer.append(idx2 - idx1)
        idx1 = idx2
    }
    return answer
}