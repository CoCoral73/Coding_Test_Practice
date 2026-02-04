import Foundation

func solution(_ n:Int) -> [Int] {
    var snail = [[Int]](repeating: [], count: n)
    var r: Int = 0, c: Int = 0, d: Int = 0
    let dr: [Int] = [1, 0, -1], dc: [Int] = [0, 1, -1]
    var num: Int = 1, dest: Int = (n * (n + 1)) / 2
    
    for i in 0..<n {
        snail[i] = [Int](repeating: 0, count: i + 1)
    }

    while num <= dest {
        snail[r][c] = num
        let (newR, newC) = (r + dr[d], c + dc[d])
        if newR < 0 || newR >= n || newC < 0 || newC >= newR + 1 {
            d = (d + 1) % 3
        } else if snail[newR][newC] != 0 {
            d = (d + 1) % 3
        }
        
        r += dr[d]
        c += dc[d]
        num += 1
    }
    
    return snail.flatMap { $0 }
}