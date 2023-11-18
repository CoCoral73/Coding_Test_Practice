import Foundation

func solution(_ record:[String]) -> [String] {
    var answer = [String](), index = 0
    var dict = Dictionary<String, (String, [Int])>()
    
    for i in 0..<record.count {
        let comp = record[i].components(separatedBy: " ")
        if comp[0] == "Enter" {
            if dict[comp[1]] == nil {
                dict.updateValue((comp[2], [index]), forKey: comp[1])
            }
            else {
                if dict[comp[1]]!.0 != comp[2] {
                    let len = dict[comp[1]]!.0.count
                    dict[comp[1]]!.1.forEach {
                        answer[$0] = comp[2] + answer[$0].suffix(answer[$0].count-len)
                    }
                    dict[comp[1]]!.0 = comp[2]
                }
                dict[comp[1]]!.1.append(index)
            }
            answer.append("\(comp[2])님이 들어왔습니다.")
            index += 1
        }
        else if comp[0] == "Leave" {
            let nickname = dict[comp[1]]!.0
            answer.append("\(nickname)님이 나갔습니다.")
            dict[comp[1]]!.1.append(index)
            index += 1
        }
        else {
            let len = dict[comp[1]]!.0.count
            dict[comp[1]]!.1.forEach {
                answer[$0] = comp[2] + answer[$0].suffix(answer[$0].count-len)
            }
            dict[comp[1]]!.0 = comp[2]
        }
    }
    return answer
}