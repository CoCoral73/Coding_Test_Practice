import Foundation

while let n = readLine() {
    let x = n.components(separatedBy: " ").map { Int($0)! }
    print(x[0] + x[1])
}