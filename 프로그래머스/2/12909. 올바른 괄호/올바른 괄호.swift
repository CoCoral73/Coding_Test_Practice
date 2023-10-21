import Foundation

func solution(_ s:String) -> Bool
{
    let s = Array(s)
    var stack = [Character]()
    
    for i in 0..<s.count {
        if s[i] == "(" {
            stack.append(s[i])
        }
        else {
            if stack.isEmpty || stack.last! == ")" { return false }
            stack.removeLast()
        }
    }
    return stack.isEmpty ? true : false
}