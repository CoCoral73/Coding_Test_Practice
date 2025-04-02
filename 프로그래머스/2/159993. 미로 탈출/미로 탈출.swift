import Foundation

class Queue<T> {
    var enqueue: [T] = []
    var dequeue: [T] = []
    
    var isEmpty: Bool { enqueue.isEmpty && dequeue.isEmpty }
    var count: Int { enqueue.count + dequeue.count }
    
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
    func clear() {
        enqueue = []
        dequeue = []
    }
}

func solution(_ maps:[String]) -> Int {
    let maps: [[String]] = maps.map { $0.map { String($0) } }
    let n: Int = maps.count, m: Int = maps[0].count
    var start: [Int] = [], end: [Int] = []
    
    for i in 0..<n {
        for j in 0..<m {
            if maps[i][j] == "S" {
                start = [i, j]
            } else if maps[i][j] == "E" {
                end = [i, j]
            }
        }
    }
    
    let queue = Queue<[Int]>()
    var isVisited: [[[Int]]] = [[[Int]]](repeating: [[Int]](repeating: [Int](repeating: Int.max, count: 2), count: m), count: n)
    let dr: [Int] = [-1, 0, 1, 0], dc: [Int] = [0, 1, 0, -1]
    
    queue.push(start)
    isVisited[start[0]][start[1]][0] = 0
    while !queue.isEmpty {
        let front = queue.pop()!
        let (r, c) = (front[0], front[1])
        
        if maps[r][c] == "L" {
            queue.clear()
            queue.push([r, c])
            isVisited[r][c][1] = isVisited[r][c][0]
            break 
        }
        
        for i in 0..<4 {
            let (newR, newC) = (r + dr[i], c + dc[i])
            if newR < 0 || newR >= n || newC < 0 || newC >= m { continue }
            if maps[newR][newC] == "X" { continue }
            if isVisited[newR][newC][0] <= isVisited[r][c][0] + 1 { continue }
            isVisited[newR][newC][0] = isVisited[r][c][0] + 1
            queue.push([newR, newC])
        }
    }
    
    while !queue.isEmpty {
        let front = queue.pop()!
        let (r, c) = (front[0], front[1])
        
        for i in 0..<4 {
            let (newR, newC) = (r + dr[i], c + dc[i])
            if newR < 0 || newR >= n || newC < 0 || newC >= m { continue }
            if maps[newR][newC] == "X" { continue }
            if isVisited[newR][newC][1] <= isVisited[r][c][1] + 1 { continue }
            isVisited[newR][newC][1] = isVisited[r][c][1] + 1
            queue.push([newR, newC])
        }
    }
    
    var answer = isVisited[end[0]][end[1]][1]
    if answer == Int.max { answer = -1 }
    return answer
}