import Foundation

func solution(_ arr:[Int], _ flag:[Bool]) -> [Int] {
    var X = [Int]()
    zip(arr, flag).forEach {
        if $0.1 { X += Array(repeating: $0.0, count: $0.0*2) }
        else { for _ in 0..<$0.0 { X.removeLast() } }
    }
    return X
}