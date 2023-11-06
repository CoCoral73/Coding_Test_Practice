import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    let tangerine = tangerine.sorted()
    var cnt = [Int]()
    var start = 0, end = 0
    var answer = 0, total = 0
    
    while start < tangerine.count {
        if end == tangerine.count || tangerine[end] != tangerine[start] {
            cnt.append(end - start)
            start = end
        }
        else { end += 1 }
    }
    
    cnt.sort(by: >)
    for i in 0..<cnt.count {
        answer += 1
        total += cnt[i]
        if total >= k { break }
    }
    
    return answer
}