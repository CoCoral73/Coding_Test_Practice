func solution(_ arr:[Int]) -> [Int] {
    var arr = arr
    arr.remove(at: arr.firstIndex(of: arr.min()!)!)
    return arr.count == 0 ? [-1] : arr
}