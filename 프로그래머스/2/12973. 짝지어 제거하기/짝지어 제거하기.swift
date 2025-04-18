import Foundation

func solution(_ s:String) -> Int{
    var stack: [Character] = []
    
    for ch in s {
        if let last = stack.last, last == ch {
            stack.removeLast()
        } else {
            stack.append(ch)
        }
    }

    return stack.isEmpty ? 1:0
}