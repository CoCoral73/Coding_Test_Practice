import Foundation

func solution(_ s:String) -> String {
    return s.lowercased().components(separatedBy: " ").map { if $0.count == 0 { return $0 } else { return String($0.first!).uppercased() + $0.suffix($0.count-1) } }.joined(separator: " ")
}