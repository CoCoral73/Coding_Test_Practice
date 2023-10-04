import Foundation

func solution(_ X:String, _ Y:String) -> String {
    var Xcount = [Int](repeating: 0, count: 10)
    X.forEach { Xcount[Int(String($0))!] += 1 }
    var Ycount = [Int](repeating: 0, count: 10)
    Y.forEach { Ycount[Int(String($0))!] += 1 }
    
    var answer = [String]()
    for i in 0...9 { answer.append(contentsOf: [String](repeating: String(i), count: min(Xcount[i], Ycount[i]))) }
    if answer.isEmpty { answer = ["-1"] }
    else if answer.filter({ $0 != "0" }).count == 0 { answer = ["0"] }
    return answer.sorted(by: >).joined()
}