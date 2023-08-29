import Foundation

func solution(_ order:[String]) -> Int {
    return order.reduce(into: 0) { $0 = $1.contains("cafelatte") ? $0 + 5000 : $0 + 4500 }
}