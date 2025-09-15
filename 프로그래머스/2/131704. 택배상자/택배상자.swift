import Foundation

func solution(_ order:[Int]) -> Int {
    var stack: [Int] = []
    var first: Int = 1, answer: Int = 0
    
    for i in 0..<order.count {
        let now = order[i]
    
        while first < now {
            stack.append(first)
            first += 1
        }
        
        if first == now {
            first += 1
            answer += 1
        } else if first > now {
            if stack.last! == now {
                stack.removeLast()
                answer += 1
            } else {
                break 
            }
        }
    }
    
    return answer
}