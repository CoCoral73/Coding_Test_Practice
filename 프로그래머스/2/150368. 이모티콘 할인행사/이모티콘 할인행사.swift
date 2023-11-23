import Foundation

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    var sale = [Int](repeating: 0, count: emoticons.count)
    var plus = 0, money = 0
    func setPercent(_ depth:Int) {
        if depth == emoticons.count {
            var p = 0, m = 0
            users.forEach {
                let percent = $0[0], max = $0[1]
                var total = 0
                for i in 0..<emoticons.count {
                    if percent <= sale[i] { total += ((100 - sale[i]) * emoticons[i]) / 100 }
                }
                if total >= max { p += 1 }
                else { m += total }
            }
     
            if p > plus { plus = p; money = m }
            else if p == plus { money = max(money, m) }
            return
        }
        
        for i in 1...4 {
            let percent = i * 10
            sale[depth] = percent
            setPercent(depth+1)
        }
    }
    
    setPercent(0)
    return [plus, money]
}