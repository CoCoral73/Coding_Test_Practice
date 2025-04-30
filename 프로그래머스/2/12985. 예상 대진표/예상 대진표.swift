import Foundation

func solution(_ n:Int, _ a:Int, _ b:Int) -> Int
{
    var a = a, b = b
    if a > b { swap(&a, &b) }

    var answer: Int = 1
    while true {
        if a % 2 == 1 && b == a + 1 { break }
        a = (a + 1) / 2
        b = (b + 1) / 2
        answer += 1
    }

    return answer
}