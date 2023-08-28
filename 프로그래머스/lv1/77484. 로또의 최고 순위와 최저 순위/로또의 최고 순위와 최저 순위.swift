import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var match = 0
    var zero = 0
    lottos.forEach { if win_nums.contains($0) { match += 1 }; zero = $0 == 0 ? zero + 1 : zero }
    return [match + zero == 0 ? 6 : 7-match-zero, match <= 1 ? 6 : 7-match]
}