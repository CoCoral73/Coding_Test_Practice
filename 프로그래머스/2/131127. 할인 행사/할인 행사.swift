import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var answer: Int = 0
    let number = Dictionary<String, Int>(uniqueKeysWithValues: zip(want, number))
    
    for i in 0...(discount.count-10) {
        var count = number
        
        for j in 0..<10 {
            if want.contains(discount[i+j]) {
                count[discount[i+j]]! -= 1
            } else {
                break 
            }
        }
        
        if count.filter { $0.value == 0 }.count == count.count {
            answer += 1
        }
    }
    
    return answer
}