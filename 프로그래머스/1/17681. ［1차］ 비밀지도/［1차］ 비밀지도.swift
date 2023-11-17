import Foundation

func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var answer = [String]()
    for i in 0..<n {
        var line = String(arr1[i] | arr2[i], radix: 2)
        line = String(repeating: "0", count: n - line.count) + line
        answer.append(line.reduce("") { return $0 + ($1 == "0" ? " " : "#") })
    }
    return answer
}