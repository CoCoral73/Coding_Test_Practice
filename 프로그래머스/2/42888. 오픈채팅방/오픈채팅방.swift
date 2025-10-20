import Foundation

func solution(_ record:[String]) -> [String] {
    var nicknameById: [String: String] = [:]
    
    let record: [[String]] = record.map {
        let str = $0.components(separatedBy: " ")
        if str.count == 3 {
            let (id, nickname) = (str[1], str[2])
            nicknameById[id] = nickname
        }
        return str
    }
    
    return record.map { 
        if $0[0] == "Enter" {
            return "\(nicknameById[$0[1]]!)님이 들어왔습니다."
        } else if $0[0] == "Leave" {
            return "\(nicknameById[$0[1]]!)님이 나갔습니다."
        } else { return "" }
    }.filter { $0 != "" }
}