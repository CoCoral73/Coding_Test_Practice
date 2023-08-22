import Foundation

func solution(_ arr:[Int]) -> Int {
    var arr = Array(arr)
    var x = 0
    while true {
        var flag = true
        for i in 0..<arr.count {
            if arr[i] >= 50 && arr[i] % 2 == 0 {
                if arr[i] / 2 != arr[i] { flag = false }
                arr[i] /= 2
            }
            else if arr[i] < 50 && arr[i] % 2 == 1 {
                if arr[i] * 2 + 1 != arr[i] { flag = false }
                arr[i] = arr[i]*2 + 1
            }
        }
        if flag { break }
        x += 1
    }
    return x
}