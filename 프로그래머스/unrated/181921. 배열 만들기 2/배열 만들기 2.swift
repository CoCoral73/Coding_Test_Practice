import Foundation

func solution(_ l:Int , _ r:Int) -> [Int] {
    var answer = [Int]()
    for n in l...r {
        var copyN = n
        var flag = 1
        while copyN > 0 {
            if copyN % 10 != 0 && copyN % 10 != 5 {
                flag = 0;
                break;
            }
            copyN /= 10
        }
        if (flag == 1) { answer.append(n) }
    }
    if answer.isEmpty { answer.append(-1) }
    return answer
}