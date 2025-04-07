import Foundation

func solution(_ n:Int) -> [[Int]] {
    var answer = [[Int]]()
    
    func hanoi(_ n: Int, _ source: Int, _ target: Int, _ aux: Int) {
        if n == 1 {
            answer.append([source, target])
        }
        else {
            hanoi(n-1, source, aux, target)
            answer.append([source, target])
            hanoi(n-1, aux, target, source)
        }
    }
    
    hanoi(n, 1, 3, 2)
    return answer
}