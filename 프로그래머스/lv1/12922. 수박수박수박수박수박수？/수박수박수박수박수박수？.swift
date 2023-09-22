func solution(_ n:Int) -> String {
    return (1...n).reduce(String()) { $0 + ($1 % 2 == 1 ? "수" : "박") }
}