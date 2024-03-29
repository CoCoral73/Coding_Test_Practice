func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    let answer = arr.filter { $0 % divisor == 0 }.sorted()
    return answer.count == 0 ? [-1] : answer
}