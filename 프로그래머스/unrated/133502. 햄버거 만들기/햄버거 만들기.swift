import Foundation

func solution(_ ingredient:[Int]) -> Int {
    var stack = [Int]()
    let comp = [1,2,3,1]
    var flag = true, answer = 0
    ingredient.forEach {
        stack.append($0)
        if stack.count >= 4 && $0 == 1 {
            let index = stack.count - 4
            flag = true;
            for i in 0..<4 { if stack[index + i] != comp[i] { flag = false; break }}
            if flag { for _ in 0..<4 { stack.removeLast() }; answer += 1 }
        }
    }
    return answer
}