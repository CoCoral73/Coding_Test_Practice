import Foundation

func solution(_ numbers:[Int]) -> String {
    return numbers.filter { $0 != 0 }.count == 0 ? "0" : numbers.map { String($0) }.sorted { $0 + $1 > $1 + $0 }.joined()
}