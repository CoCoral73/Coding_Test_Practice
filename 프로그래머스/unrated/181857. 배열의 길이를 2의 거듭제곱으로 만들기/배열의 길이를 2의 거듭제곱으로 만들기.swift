import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var size = 1
    while arr.count > size { size *= 2 }
    return arr.count == size ? arr : arr + Array(repeating: 0, count: size-arr.count)
}