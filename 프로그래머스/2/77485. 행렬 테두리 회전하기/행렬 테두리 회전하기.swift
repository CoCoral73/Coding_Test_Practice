import Foundation

func solution(_ rows:Int, _ columns:Int, _ queries:[[Int]]) -> [Int] {
    var matrix = (0..<rows).map { row in (1...columns).map { col in row*columns + col } }
    
    func rotate(_ query: [Int]) -> Int {
        let query = query.map { $0 - 1 }
        let (x1, y1, x2, y2) = (query[0], query[1], query[2], query[3])
        let tmp = matrix[x1][y1]
        var minValue = rows * columns
        
        for r in stride(from: x1+1, through: x2, by: 1) {
            matrix[r-1][y1] = matrix[r][y1]
            minValue = min(minValue, matrix[r][y1])
        }
        for c in stride(from: y1+1, through: y2, by: 1) {
            matrix[x2][c-1] = matrix[x2][c]
            minValue = min(minValue, matrix[x2][c])
        }
        for r in stride(from: x2-1, through: x1, by: -1) {
            matrix[r+1][y2] = matrix[r][y2]
            minValue = min(minValue, matrix[r][y2])
        }
        for c in stride(from: y2-1, through: y1+1, by: -1) {
            matrix[x1][c+1] = matrix[x1][c]
            minValue = min(minValue, matrix[x1][c])
        }
        
        matrix[x1][y1+1] = tmp
        minValue = min(minValue, tmp)
        
        return minValue
    }
    
    var answer = [Int]()
    for query in queries {
        answer.append(rotate(query))
    }
    return answer
}