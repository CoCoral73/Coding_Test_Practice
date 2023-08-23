import Foundation

struct info {
    var idx: Int
    var users: [String]
    init(_ idx: Int) {
        self.idx = idx
        self.users = [String]()
    }
}

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var answer = Array(repeating: 0, count: id_list.count)
    var dict: [String: info] = [:]  //value: 나를 신고한 유저 목록
    id_list.enumerated().forEach { dict[$0.element] = info($0.offset) }
    
    report.forEach {
        let rep = $0.components(separatedBy: " ")
        if !dict[rep[1]]!.users.contains(rep[0]) { dict[rep[1]]?.users.append(rep[0]) }
    }
    
    id_list.forEach {
        if dict[$0]!.users.count >= k {
            dict[$0]!.users.forEach { answer[dict[$0]!.idx] += 1 }
        }
    }
    return answer
}