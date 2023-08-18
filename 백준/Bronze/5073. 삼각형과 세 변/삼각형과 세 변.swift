import Foundation

func solution(_ x:Int, _ y:Int, _ z:Int) -> Void {
    let set = Set([x, y, z])
    if set.count == 1 { print("Equilateral"); return }
    var sum = x + y + z - set.max()!
    if sum <= set.max()! { print("Invalid"); return }
    if set.count == 2 { print("Isosceles"); return }
    print("Scalene")
}

while true {
    let n = readLine()!.components(separatedBy: [" "]).map { Int($0)! }
    let (a, b, c) = (n[0], n[1], n[2])
    if a == 0 && b == 0 && c == 0 { break }
    solution(a, b, c)
}
