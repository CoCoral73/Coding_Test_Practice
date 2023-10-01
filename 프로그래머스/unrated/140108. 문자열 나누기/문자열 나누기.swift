import Foundation

func solution(_ s:String) -> Int {
    var answer = 0
    var flag = false, cnt1 = 0, cnt2 = 0, x: Character?
    for i in 0..<s.count {
        if !flag {
            x = s[s.index(s.startIndex, offsetBy: i)]
            cnt1 = 1; cnt2 = 0
            flag = true
        }
        else {
            if s[s.index(s.startIndex, offsetBy: i)] == x { cnt1 += 1 }
            else { cnt2 += 1 }
            if cnt1 == cnt2 { answer += 1; flag = false }
        }
    }
    if flag { answer += 1 }
    return answer
}