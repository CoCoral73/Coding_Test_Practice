import Foundation

let input = readLine()!.components(separatedBy: [" "]).map { $0 }
let (str1, str2) = (input[0], input[1])
print(str1+str2)