import Foundation

func solution(_ new_id:String) -> String {
    var arr: [Character] = []
    //step1, 2
    for ch in new_id {
        if ch.isLetter {
            if ch.isUppercase { arr.append(Character(ch.lowercased())) }
            else { arr.append(ch) }
        }
        else if ch.isNumber { arr.append(ch) }
        else if ch == "-" || ch == "_" || ch == "." { arr.append(ch) }
    }

    //step3
    var start = 0, end = 0, i = 0
    var flag = false
    while true {
        if arr[i] == "." {
            if (!flag) {
                start = i
                end = i
                flag = true
            }
            else { end = i }
        }
        else {
            if end - start >= 1 {
                arr.removeSubrange(start..<end)
                i = start
                end = start
            }
            flag = false
        }
        i += 1
        if i >= arr.count {
            if end - start >= 1 { arr.removeSubrange(start..<end) }
            break
        }
    }
    
    //step4
    if arr.first == "." { arr.removeFirst() }
    if arr.last == "." { arr.removeLast() }
    
    //step5
    if arr.isEmpty { arr.append("a") }
    
    //step6
    if arr.count >= 16 {
        arr.removeSubrange(15...)
        if arr.last == "." { arr.removeLast() }
    }
    
    //step7
    while arr.count <= 2 { arr.append(arr.last!) }
    
    var answer = String()
    for ch in arr { answer.append(ch) }
    return answer
}