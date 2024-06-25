import Foundation

let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }
print(n[0]-n[1])