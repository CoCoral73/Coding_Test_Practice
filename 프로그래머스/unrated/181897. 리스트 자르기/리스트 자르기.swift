import Foundation

func solution(_ n:Int, _ slicer:[Int], _ num_list:[Int]) -> [Int] {
    switch n {
    case 1:
        return Array(num_list[...slicer[1]])
    case 2:
        return Array(num_list[slicer[0]...])
    case 3:
        return Array(num_list[slicer[0]...slicer[1]])
    default:
        var answer = [Int]()
        for i in stride(from: slicer[0], through: slicer[1], by: slicer[2]) { answer.append(num_list[i]) }
        return answer
    }
}