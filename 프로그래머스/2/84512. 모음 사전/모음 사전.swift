import Foundation

func solution(_ word:String) -> Int {
    let word = word.map { String($0) }
    let vowel = ["A", "E", "I", "O", "U"]
    
    var cur_word: [String] = [], answer: Int = -1
    func dfs(_ depth: Int) -> Bool {
        answer += 1
        
        if cur_word == word { return true }
        if depth == 5 { return false }
        
        for i in 0..<5 {
            cur_word.append(vowel[i])
            if dfs(depth + 1) { return true }
            cur_word.removeLast()
        }
        return false 
    }
    
    _ = dfs(0)
    
    return answer
}