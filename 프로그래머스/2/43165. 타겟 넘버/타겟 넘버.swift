import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    let count = numbers.count
    var answer = 0
    
    func dfs(_ depth: Int, _ sum: Int) {
        if depth == count {
            if sum == target { answer += 1 }
            return
        }
        
        dfs(depth + 1, sum + numbers[depth])
        dfs(depth + 1, sum - numbers[depth])
    }
    
    dfs(0, 0)
    return answer
}