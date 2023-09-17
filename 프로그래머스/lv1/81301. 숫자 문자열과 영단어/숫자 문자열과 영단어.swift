import Foundation

func solution(_ s:String) -> Int {
    let numbers = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    var s = s
    numbers.enumerated().forEach {
        s = s.replacingOccurrences(of: $0.element, with: String($0.offset))
    }
    return Int(s)!
}