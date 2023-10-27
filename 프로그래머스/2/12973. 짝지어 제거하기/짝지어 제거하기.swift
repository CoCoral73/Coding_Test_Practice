import Foundation

func solution(_ s:String) -> Int{
    var stack = [Character](repeating: " ", count: s.count), s = Array(s)
    var top = -1
    s.forEach {
        if top == -1 || stack[top] != $0 {
            top += 1
            stack[top] = $0
        }
        else if stack[top] == $0 {
            top -= 1
        }
    }
    return top == -1 ? 1 : 0
}