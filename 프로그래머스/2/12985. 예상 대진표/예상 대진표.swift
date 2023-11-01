import Foundation

func solution(_ n:Int, _ a:Int, _ b:Int) -> Int
{
    var answer = 1, a = a, b = b
    
    while true {
        let x = min(a, b), y = max(a, b)
        if x + 1 == y && x % 2 == 1 { break }
        a = (a + 1) / 2
        b = (b + 1) / 2
        answer += 1
    }
    return answer
}