import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var lost = lost.sorted(), reserve = reserve.sorted()
    for i in 1...n {
        if lost.contains(i) && reserve.contains(i) {
            lost.removeAll(where: {$0 == i})
            reserve.removeAll(where: {$0 == i})
        }
    }
    var answer = n - lost.count
    reserve.forEach { x in
        if x-1 >= 1 && lost.contains(x-1) { lost.removeAll(where: {$0 == x-1}); answer += 1 }
        else if x+1 <= n && lost.contains(x+1) { lost.removeAll(where: {$0 == x+1}); answer += 1 }
    }
    return answer
}