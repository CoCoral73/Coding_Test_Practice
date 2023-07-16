import Foundation

func solution(_ num_list:[Int]) -> Int {
    var odd = 0, even = 0
    for n in num_list {
        if n % 2 == 1 { odd = odd*10+n }
        else { even = even*10+n }
    }
    return odd+even
}