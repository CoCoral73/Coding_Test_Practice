import Foundation

func solution(_ n:Int) -> Int {
    var chess = [Int](repeating: -1, count: n)
    
    func check(_ row: Int, _ col: Int) -> Bool {
        for i in stride(from: 0, to: row, by: 1) {
            if chess[i] == col || row - i == abs(col - chess[i]) {
                return false 
            }
        }
        return true 
    }
    
    var answer: Int = 0
    func backtracking(_ depth: Int) {
        if depth == n {
            answer += 1
            return 
        }
        
        for i in 0..<n {
            if check(depth, i) {
                chess[depth] = i
                backtracking(depth + 1)
            }
        }
    }
    
    backtracking(0)
    return answer
}