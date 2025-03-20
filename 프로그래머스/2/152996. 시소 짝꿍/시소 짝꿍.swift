import Foundation

func solution(_ weights:[Int]) -> Int64 {
    var dict = Dictionary<Int, Int>()
    var answer = 0
    
    for w in weights {
        if let value = dict[w] {
            dict.updateValue(value + 1, forKey: w)
        } else {
            dict.updateValue(1, forKey: w)
        }
    }
    
    for w in dict.keys {
        let myValue = dict[w]!
        
        answer += myValue * (myValue - 1) / 2
        
        if let yourValue = dict[2*w] {
            answer += myValue * yourValue
        }
        
        if w.isMultiple(of: 2), let yourValue = dict[3*w/2] {
            answer += myValue * yourValue
        }
        
        if w.isMultiple(of: 3), let yourValue = dict[4*w/3] {
            answer += myValue * yourValue 
        }
    }
    
    return Int64(answer)
}