import Foundation

func solution(_ answers:[Int]) -> [Int] {
    let sol2 = [1,3,4,5]
    let sol3 = [3,1,2,4,5]
    var cnt = [0, 0, 0]
    cnt[0] = answers.enumerated().reduce(0, { return $1.offset % 5 + 1 == $1.element ? $0 + 1 : $0 })
    cnt[1] = answers.enumerated().reduce(0, {
        if $1.offset % 2 == 0 && $1.element == 2 { return $0 + 1 }
        else if $1.offset % 2 == 1 && sol2[($1.offset / 2) % 4] == $1.element { return $0 + 1 }
        else { return $0 }
    })
    cnt[2] = answers.enumerated().reduce(0, { sol3[($1.offset / 2) % 5] == $1.element ? $0 + 1 : $0 })

    var answer = [1]
    if cnt[0] < cnt[1] { answer = [2] }
    else if cnt[0] == cnt[1] { answer = [1,2] }
    if cnt[answer[0]-1] < cnt[2] { answer = [3] }
    else if cnt[answer[0]-1] == cnt[2] { answer.append(3) }
    return answer
}
