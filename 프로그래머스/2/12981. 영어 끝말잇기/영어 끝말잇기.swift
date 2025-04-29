import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var setOfWords: Set<String> = []
    var last: Character? = nil
    
    for i in 0..<words.count {
        let answer = [i % n + 1, i / n + 1]
        
        if let last = last, last != words[i].first! || words[i].count == 1 || setOfWords.contains(words[i]) {
            return answer
        }
        
        setOfWords.insert(words[i])
        last = words[i].last!
    }
    
    return [0, 0]
}