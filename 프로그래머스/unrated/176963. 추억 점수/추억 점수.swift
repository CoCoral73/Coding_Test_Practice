import Foundation

func solution(_ name:[String], _ yearning:[Int], _ photo:[[String]]) -> [Int] {
    var dict = Dictionary<String, Int>()
    zip(name, yearning).forEach { dict.updateValue($1, forKey: $0) }
    return photo.map { $0.reduce(0) { $0 + (dict[$1] ?? 0) } }
}