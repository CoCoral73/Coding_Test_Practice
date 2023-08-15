import Foundation

func solution(_ a:Int, _ b:Int, _ c:Int, _ d:Int) -> Int {
    let arr = [a, b, c, d]
    let set = Array(Set(arr))
    if set.count == 1 { return 1111*set.first! }
    if set.count == 4 { return set.min()! }
    if set.count == 2 {
        if (arr.filter { $0 == set[0] }.count == 2) { return (set[0]+set[1])*(abs(set[0]-set[1])) }
        let n = arr.filter { $0 == set[0] }.count == 3 ? 10*set[0]+set[1] : 10*set[1]+set[0]
        return n*n
    }
    var answer = 1
    for i in set {
        if (arr.filter { $0 == i }.count == 1) { answer *= i }
    }
    return answer
}