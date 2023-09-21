func solution(_ num:Int) -> Int {
    var num = num, answer = 0
    while num != 1 {
        num = num % 2 == 0 ? num / 2 : num * 3 + 1
        answer += 1
        if answer > 500 { answer = -1; break; }
    }
    return answer
}