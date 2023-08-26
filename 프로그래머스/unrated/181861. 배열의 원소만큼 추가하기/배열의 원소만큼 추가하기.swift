import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var X = [Int]()
    arr.forEach {
        X += [Int](repeating: $0, count: $0)
    }
    return X
}