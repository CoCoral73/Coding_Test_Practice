import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var dict: [Int: Int] = [:]
    
    tangerine.forEach { 
        if let _ = dict[$0] {
            dict[$0]! += 1
        } else {
            dict.updateValue(1, forKey: $0)
        }
    }
    
    let sortedKey = dict.keys.sorted {
        return dict[$0]! > dict[$1]!
    }

    var total = 0
    for i in 0..<sortedKey.count {
        let count = dict[sortedKey[i]]!
        
        if total + count >= k {
            return i + 1
        } else {
            total += count
        }
    }
    return 0
}