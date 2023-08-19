import Foundation

struct MyDate {
    var year: Int
    var month: Int
    var day: Int
    var days: Int
    
    init(_ date:String) {
        let date = Array(date)
        year = Int(String(date[...3]))!
        month = Int(String(date[5...6]))!
        day = Int(String(date[8...9]))!
        days = year*12*28 + month*28 + day
    }
}

func solution(_ today:String, _ terms:[String], _ privacies:[String]) -> [Int] {
    let today = MyDate(today)
    var types: [String: Int] = [:]
    for i in 0..<terms.count {
        var n = String(terms[i].suffix(terms[i].count-2))
        types[String(terms[i].prefix(1))] = Int(n)!
    }
    
    var answer = [Int]()
    for i in 0..<privacies.count {
        let privacy = MyDate(privacies[i])
        let type = String(privacies[i].suffix(1))
        if privacy.days + types[type]!*28 - 1 < today.days { answer.append(i+1) }
    }
    return answer
}