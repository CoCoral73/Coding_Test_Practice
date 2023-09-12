import Foundation

func solution(_ numbers:[Int], _ hand:String) -> String {
    var keypad = [(3,1), (0,0), (0,1), (0,2), (1,0), (1,1), (1,2), (2,0), (2,1), (2,2)]
    var now_left = (3,0), now_right = (3,2)
    var answer = ""
    
    numbers.forEach {
        if $0 % 3 == 1 { answer += "L"; now_left = keypad[$0] }
        else if $0 != 0 && $0 % 3 == 0 { answer += "R"; now_right = keypad[$0] }
        else {
            let d_left = abs(keypad[$0].0 - now_left.0) + abs(keypad[$0].1 - now_left.1)
            let d_right = abs(keypad[$0].0 - now_right.0) + abs(keypad[$0].1 - now_right.1)
            if d_left < d_right || (d_left == d_right && hand == "left") { answer += "L"; now_left = keypad[$0] }
            else { answer += "R"; now_right = keypad[$0] }
        }
    }
    return answer
}