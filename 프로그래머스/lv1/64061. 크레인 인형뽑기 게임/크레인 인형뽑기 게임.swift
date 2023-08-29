import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    let N = board.count
    var tops = [Int](repeating: N, count: N)
    for i in 0..<N {
        for j in 0..<N { if tops[j] == N && board[i][j] > 0 { tops[j] = i }}
    }
    
    var basket = [Int]()
    var answer = 0
    moves.forEach {
        let col = $0 - 1
        if tops[col] < N {
            if basket.isEmpty || board[tops[col]][col] != basket.last! { basket.append(board[tops[col]][col]) }
            else { basket.removeLast(); answer += 2 }
            tops[col] += 1
        }
    }
    return answer
}