import Foundation

func solution(_ s:String) -> Int {
    let number = ["zero":0, "one":1, "two":2, "three":3, "four":4, "five":5, "six":6, "seven":7, "eight":8, "nine":9]
    var s = s
    number.forEach { s = s.replacingOccurrences(of: $0.key, with: String($0.value)) }
    return Int(s)!
}