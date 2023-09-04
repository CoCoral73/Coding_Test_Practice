import Foundation

func solution(_ picture:[String], _ k:Int) -> [String] {
    let N = picture.count * k, M = picture[0].count * k
    var answer = [String](repeating: "", count: N)
    for i in 0..<N {
        let line = Array(picture[i/k])
        for j in 0..<M {
            answer[i].append(String(line[j/k]))
        }
    }
    return answer
}