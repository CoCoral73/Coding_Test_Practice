import Foundation

func searchFx(_ x: Int64) -> Int64 {
    let bx = Array(String(x, radix: 2))
    
    var count_0: Int = 0
    for i in stride(from: bx.count-1, through: 0, by: -1) {
        if bx[i] == "0" { break }
        count_0 += 1
    }
    
    return x + (count_0 < 2 ? 1 : Int64(pow(2, Double(count_0 - 1))))
}

func solution(_ numbers:[Int64]) -> [Int64] {
    return numbers.map { searchFx($0) }
}