import Foundation

func solution(_ num_list:[Int]) -> Int {
    var rst1 = 1, rst2 = 0
    for n in num_list {
        rst1 *= n
        rst2 += n
    }
    return rst1 < rst2*rst2 ? 1 : 0
}