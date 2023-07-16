import Foundation

func power(_ a:Int, _ b:Int) -> Int {
    var answer = 1
    for _ in 0..<b { answer *= a }
    return answer
}
func solution(_ a:Int, _ b:Int, _ c:Int) -> Int {
    var answer = a + b + c
    if a == b || b == c || a == c { answer *= power(a,2)+power(b,2)+power(c,2) }
    if a == b && b == c { answer *= power(a,3)+power(b,3)+power(c,3) }
    return answer
}