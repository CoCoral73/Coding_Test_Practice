import Foundation

let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }
let (W, H, X, Y, P) = (n[0], n[1], n[2], n[3], n[4])
let R = H/2
let o1 = (X, Y+R)
let o2 = (X+W, Y+R)

func solution(_ x:Int, _ y:Int) -> Int {
    let o1d = sqrt(pow(Double(o1.0-x), 2)+pow(Double(o1.1-y), 2))
    let o2d = sqrt(pow(Double(o2.0-x), 2)+pow(Double(o2.1-y), 2))
    if o1d <= Double(R) || o2d <= Double(R) { return 1 }
    return 0
}

var answer = 0
for _ in 0..<P {
    let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }
    let (x, y) = (n[0], n[1])
    if (X <= x && x <= X+W) && (Y <= y && y <= Y+H) { answer += 1 }
    else { answer += solution(x, y) }
}
print(answer)