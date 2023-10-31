import Foundation

func solution(_ n:Int) -> Int {
    var ans:Int = 0, n = n
    
    while n > 0 {
        if n % 2 == 0 { n /= 2 }
        else { ans += 1; n = (n - 1) / 2 }
    }
    
    return ans
}