import Foundation

func solution(_ n:Int) -> Int {
    return Array(String(n)).reduce(0) { $0 + Int(String($1))! }
}