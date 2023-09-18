import Foundation

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    var sale = [Int](repeating: 0, count: emoticons.count)
    let percent = [10, 20, 30, 40]
    var answer = [0, 0]
    
    func dfs(_ depth: Int) {
        if depth == sale.count {
            var plus = 0, money = 0
            users.forEach { user in
                var total = 0
                zip(sale, emoticons).forEach {
                    if user[0] <= $0.0 { total += ($0.1 * (100 - $0.0) / 100) }
                }
                if total >= user[1] { plus += 1; total = 0 }
                money += total
            }
            
            if plus > answer[0] { answer[0] = plus; answer[1] = money }
            else if plus == answer[0] && money > answer[1] { answer[1] = money }
            
            return
        }
        
        percent.forEach {
            sale[depth] = $0
            dfs(depth+1)
        }
    }
    
    dfs(0)
    
    return answer
}