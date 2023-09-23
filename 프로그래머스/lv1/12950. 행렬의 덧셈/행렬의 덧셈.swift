func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    return zip(arr1, arr2).map { (a1, a2) in zip(a1, a2).map { $0.0 + $0.1 } }
}