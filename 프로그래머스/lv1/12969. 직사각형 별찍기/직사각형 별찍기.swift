import Foundation

let x = readLine()!.components(separatedBy: [" "]).map { Int($0)! }
let (n, m) = (x[0], x[1])

for _ in 0..<m { print(String(repeating: "*", count: n)) }