import Foundation

func solution(_ food:[Int]) -> String {
    var str = String()
    for i in 1..<food.count {
        str += String(repeating: String(i), count: food[i]/2)
    }
    return str + "0" + str.reversed()
}