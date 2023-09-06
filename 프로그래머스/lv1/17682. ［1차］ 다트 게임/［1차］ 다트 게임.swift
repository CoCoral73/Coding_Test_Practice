func solution(_ dartResult:String) -> Int {
    var arr = [Int](), last = -1
    let dartResult = Array(dartResult)
    var score = 0
    
    dartResult.enumerated().forEach {
        if $0.element.isNumber { score = score * 10 + Int(String($0.element))! }
        else if $0.element.isLetter {
            if $0.element == "D" { score *= score }
            else if $0.element == "T" { score *= (score*score) }
            if $0.offset + 1 >= dartResult.count || dartResult[$0.offset + 1].isNumber {
                arr.append(score)
                last += 1
                score = 0
            }
        }
        else {
            if $0.element == "*" {
                if last >= 0 { arr[last] *= 2 }
                arr.append(score*2)
                last += 1
                score = 0
            }
            else { arr.append(-score); last += 1; score = 0 }
        }
    }
    return arr.reduce(0, +)
}