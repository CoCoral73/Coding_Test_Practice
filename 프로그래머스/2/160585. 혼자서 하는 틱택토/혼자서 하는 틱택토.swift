import Foundation

func solution(_ board:[String]) -> Int {
    let board = board.map { $0.map { String($0) } }
    
    var countOfO: Int = 0, countOfX: Int = 0
    for i in 0..<3 {
        for j in 0..<3 {
            if board[i][j] == "O" {
                countOfO += 1
            } else if board[i][j] == "X" {
                countOfX += 1
            }
        }
    }
    
    let arrayOfO3 = ["O", "O", "O"], arrayOfX3 = ["X", "X", "X"]
    var O3: Int = 0, X3: Int = 0
    for i in 0..<3 {
        if board[i] == arrayOfO3 {
            O3 += 1
        } else if board[i] == arrayOfX3 {
            X3 += 1
        }
        
        if [board[0][i], board[1][i], board[2][i]] == arrayOfO3 {
            O3 += 1
        } else if [board[0][i], board[1][i], board[2][i]] == arrayOfX3 {
            X3 += 1
        }
    }
    
    if [board[0][0], board[1][1], board[2][2]] == arrayOfO3 {
        O3 += 1
    } else if [board[0][0], board[1][1], board[2][2]] == arrayOfX3 {
        X3 += 1
    }
    
    if [board[2][0], board[1][1], board[0][2]] == arrayOfO3 {
        O3 += 1
    } else if [board[2][0], board[1][1], board[0][2]] == arrayOfX3 {
        X3 += 1
    }
    
    if countOfO == countOfX && O3 == 0 {
        return 1
    }
    
    if countOfO == countOfX + 1 && X3 == 0 {
        return 1
    }
    
    return 0
}