import Foundation

func solution(_ number:[Int]) -> Int {
    var answer = 0, sum = 0;
    
    func dfs(_ depth:Int, _ index:Int) {
        if depth == 3 {
            if sum == 0 { answer += 1 }
            return ;
        }
        
        for i in index..<number.count {
            sum += number[i]
            dfs(depth+1, i+1)
            sum -= number[i]
        }
    }
    
    dfs(0, 0)
    return answer
}