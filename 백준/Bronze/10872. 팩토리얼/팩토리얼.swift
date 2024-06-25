import Foundation

var N = Int(readLine()!)!
N = N == 0 ? 1 : N
let result = (1...N).reduce(1, { return $0 * $1 })
print(result)