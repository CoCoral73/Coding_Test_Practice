import Foundation

class Queue<T> {
    var enqueue: [T] = []
    var dequeue: [T] = []
    
    var isEmpty: Bool { enqueue.isEmpty && dequeue.isEmpty }
    
    func push(_ x: T) {
        enqueue.append(x)
    }
    func pop() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue = []
        }
        return dequeue.removeLast()
    }
}

func solution(_ board:[String]) -> Int {
    let board = board.map { $0.map { String($0) } }
    let n = board.count, m = board[0].count
    var start: [Int] = [], goal: [Int] = []
    
    for i in 0..<n {
        for j in 0..<m {
            if board[i][j] == "R" { start = [i, j] }
            else if board[i][j] == "G" { goal = [i, j] }
        }
    }
    
    let dr = [-1, 0, 1, 0], dc = [0, 1, 0, -1]
    var isVisited = [[Int]](repeating: [Int](repeating: Int.max, count: m), count: n)
    
    let queue = Queue<[Int]>()
    queue.push(start)
    isVisited[start[0]][start[1]] = 0
    while !queue.isEmpty {
        let front = queue.pop()!
        let (r, c) = (front[0], front[1])
        
        for i in 0..<4 {
            var (newR, newC) = (r, c)
            while true {
                let (nextR, nextC) = (newR + dr[i], newC + dc[i])
                if nextR < 0 || nextR >= n || nextC < 0 || nextC >= m {
                    break
                }
                if board[nextR][nextC] == "D" {
                    break 
                }
                (newR, newC) = (nextR, nextC)
            }
            
            if isVisited[newR][newC] <= isVisited[r][c] + 1 {
                continue 
            }
            
            isVisited[newR][newC] = isVisited[r][c] + 1
            queue.push([newR, newC])
        }
    }
    
    var answer = isVisited[goal[0]][goal[1]]
    if answer == Int.max {
        answer = -1 
    }
    
    return answer
}