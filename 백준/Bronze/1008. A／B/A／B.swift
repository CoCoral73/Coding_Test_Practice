import Foundation

let n = readLine()!.components(separatedBy: [" "]).map { Double($0)! }
print(n[0]/n[1])