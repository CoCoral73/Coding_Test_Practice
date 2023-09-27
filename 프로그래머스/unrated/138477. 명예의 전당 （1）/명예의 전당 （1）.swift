import Foundation

func solution(_ k:Int, _ score:[Int]) -> [Int] {
    var rank = [Int]()
    return score.map {
        rank.append($0)
        rank.sort(by: >)
        return rank.count < k ? rank.min()! : rank[k-1]
    }
}