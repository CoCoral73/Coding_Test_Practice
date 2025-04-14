import Foundation

func solution(_ s:String) -> Bool
{
    var stack: [Character] = []
    
    for c in s {
        if c == "(" {
            stack.append(c)
        } else {
            let top = stack.popLast()
            if top == nil || top != "(" {
                return false 
            }
        }
    }
    
    if !stack.isEmpty {
        return false 
    }
    
    return true
}