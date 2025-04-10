import Foundation

func solution(_ plans:[[String]]) -> [String] {
    var plans = plans.sorted { plan1, plan2 in
        return plan1[1] < plan2[1]
    }
    
    var stack = [(String, Int)]()
    var answer: [String] = []
    
    for i in 0..<plans.count {
        if i == plans.count - 1 {
            answer.append(plans[i][0])
            continue
        }

        let now = plans[i][1].components(separatedBy: [":"]).map { Int($0)! }
        let now_time = now[0] * 60 + now[1], playtime = Int(plans[i][2])!
        var end_time = now_time + playtime
        let next = plans[i+1][1].components(separatedBy: [":"]).map { Int($0)! }
        let next_time = next[0] * 60 + next[1]

        if next_time >= end_time {
            answer.append(plans[i][0])
            
            while !stack.isEmpty {
                let last = stack.removeLast()

                if end_time+last.1 > next_time {
                    stack.append((last.0, last.1 - (next_time - end_time)))
                    break
                } else {
                    answer.append(last.0)
                    end_time += last.1
                }
            }
        } else {
            stack.append((plans[i][0], end_time - next_time))
        }
    }
    
    while !stack.isEmpty {
        answer.append(stack.removeLast().0)
    }
    return answer
}