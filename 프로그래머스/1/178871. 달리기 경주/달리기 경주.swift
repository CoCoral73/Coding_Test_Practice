import Foundation

func solution(_ players:[String], _ callings:[String]) -> [String] {
    var players = players
    var rank = Dictionary<String, Int>(uniqueKeysWithValues: zip(players, (0..<players.count)))
    func swap(_ i:Int, _ j:Int) {
        var tmp = players[i]
        players[i] = players[j]
        players[j] = tmp
    }
    callings.forEach {
        let index = rank[$0]!
        swap(index, index-1)
        rank[$0]! -= 1
        rank[players[index]]! += 1
    }
    
    return players
}