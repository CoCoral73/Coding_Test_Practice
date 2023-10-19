import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int {
    let len = A.count
    let A = A.sorted(by: <)
    let B = B.sorted(by: >)
    return zip(A, B).reduce(0, { $1.0 * $1.1 + $0 })
}