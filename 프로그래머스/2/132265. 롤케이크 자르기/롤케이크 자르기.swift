import Foundation

func solution(_ topping:[Int]) -> Int {
    var count1 = [Int](repeating: 0, count: 10001), count2 = count1
    var set1: Set<Int> = [], set2 = Set(topping)
    var answer: Int = 0
    
    topping.forEach { count2[$0] += 1 }
    
    for i in 0..<(topping.count-1) {
        let top = topping[i]
        count1[top] += 1
        set1.insert(top)
        
        count2[top] -= 1
        if count2[top] == 0 {
            set2.remove(top)
        }
        
        if set1.count == set2.count {
            answer += 1
        }
    }
    
    return answer
}