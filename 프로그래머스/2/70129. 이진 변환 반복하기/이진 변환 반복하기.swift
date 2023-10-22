import Foundation

func solution(_ s:String) -> [Int] {
    var s = s
    var a = 0, b = 0
    while s.count != 1 {
        let tmp = s.replacingOccurrences(of: "0", with: "")
        b += (s.count - tmp.count)
        s = String(tmp.count, radix: 2)
        a += 1
    }
    return [a, b]
}