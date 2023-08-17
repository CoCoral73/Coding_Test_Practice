import Foundation

func solution(_ arr:[Int], _ k:Int) -> [Int] {
    var answer = [Int]()
    if k % 2 == 1 { answer = arr.map{ $0 * k } }
    else { answer = arr.map{ $0 + k } }
    return answer
}