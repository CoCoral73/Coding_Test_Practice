import Foundation

func solution(_ s:String) -> [Int] {
    let s = Array(s)
    return s.enumerated().map {
        let index = s[0..<$0.offset].lastIndex(of: $0.element)
        return index == nil ? -1 : $0.offset - index!
    }
}