import Foundation

func solution(_ rank:[Int], _ attendance:[Bool]) -> Int {
    let top = rank.enumerated().filter { attendance[$0.offset] }.sorted(by: { $0.element < $1.element }).map { $0.offset }[..<3]
    return top[0]*10000 + top[1]*100 + top[2]
}