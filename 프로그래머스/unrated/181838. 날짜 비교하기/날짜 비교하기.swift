import Foundation

func solution(_ date1:[Int], _ date2:[Int]) -> Int {
    for i in 0..<3 {
        if date1[i] != date2[i] { return date1[i] < date2[i] ? 1 : 0 }
    }
    return 0
}