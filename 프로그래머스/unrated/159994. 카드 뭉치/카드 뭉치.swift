import Foundation

func solution(_ cards1:[String], _ cards2:[String], _ goal:[String]) -> String {
    var index1 = 0, index2 = 0
    goal.forEach {
        if index1 < cards1.count && $0 == cards1[index1] { index1 += 1 }
        else if index2 < cards2.count && $0 == cards2[index2] { index2 += 1 }
    }
    return index1 + index2 == goal.count ? "Yes" : "No"
}