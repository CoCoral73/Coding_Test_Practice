import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var answer = String()
    let type = ["RT", "CF", "JM", "AN"]
    var check: [Character: Int] = [:]
    
    type.forEach {
        check[$0.first!] = 0
        check[$0.last!] = 0
    }
    zip(survey, choices).forEach {
        if $0.1 < 4 { check[$0.0.first!]! += (4-$0.1) }
        else { check[$0.0.last!]! += ($0.1-4) }
    }
    
    for i in 0..<4  {
        answer += check[type[i].first!]! >= check[type[i].last!]! ? String(type[i].first!) : String(type[i].last!)
    }
     
    return answer
}