import Foundation

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    return (left...right).map { Int(max($0 / Int64(n), $0 % Int64(n)) + 1) }
}
