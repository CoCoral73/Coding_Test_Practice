import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    let N = board.count
    var board = board, top = [Int](repeating: -1, count: N)
    
    for i in 0..<N {
        for j in 0..<N {
            if top[j] == -1 && board[i][j] != 0 { top[j] = i }
        }
    }
    
    var basket = [Int]()
    var answer = 0
    for i in 0..<moves.count {
        let col = moves[i] - 1
        if top[col] == N { continue }
        let pick = board[top[col]][col]
        if basket.isEmpty || basket.last != pick {
            basket.append(pick)
        }
        else {
            basket.removeLast()
            answer += 2
        }
        top[col] += 1
    }
    return answer
}