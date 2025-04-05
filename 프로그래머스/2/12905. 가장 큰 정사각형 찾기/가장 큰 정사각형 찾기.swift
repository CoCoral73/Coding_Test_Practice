import Foundation

func solution(_ board:[[Int]]) -> Int
{
    var answer:Int = 0
    var square = [[Int]](repeating: [Int](repeating: 0, count: board[0].count), count: board.count)
    
    for i in 0..<board.count {
        for j in 0..<board[0].count {
            if board[i][j] == 0 { 
                square[i][j] = 0
            } else {
                if i == 0 || j == 0 {
                    square[i][j] = 1
                } else {
                    square[i][j] = 1 + min(square[i-1][j-1], square[i-1][j], square[i][j-1])
                }
            }
            
            answer = max(answer, square[i][j])
        }
    }

    return answer * answer
}