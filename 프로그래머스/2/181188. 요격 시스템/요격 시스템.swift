import Foundation

func solution(_ targets:[[Int]]) -> Int {
    let sorted = targets.sorted(by: { return $0[1] < $1[1] })
    //print(sorted)
    
    var ss = -1, ee = -1
    var answer = 0
    for i in 0..<sorted.count {
        let (s, e) = (sorted[i][0], sorted[i][1])
        if ss == -1 { ss = s; ee = e; if i == sorted.count - 1 { answer += 1 }; continue }
        if s < ee { ss = s; if i == sorted.count - 1 { answer += 1; break }; continue }
        else { answer += 1; ss = s; ee = e; if i == sorted.count - 1 { answer += 1 } }
    }
    
    return answer
}