import Foundation

func solution(_ arr:[Int], _ intervals:[[Int]]) -> [Int] {
    var answer = [Int](arr[intervals[0][0]...intervals[0][1]])
    answer.append(contentsOf: arr[intervals[1][0]...intervals[1][1]])
    return answer
}