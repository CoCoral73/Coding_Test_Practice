func solution(_ x:Int, _ n:Int) -> [Int64] {
    if x == 0 { return [Int64](repeating: 0, count: n) }
    return stride(from: Int64(x), through: Int64(x)*Int64(n), by: x).map { $0 }
}
