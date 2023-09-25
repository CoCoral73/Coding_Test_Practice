import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var sizes = sizes
    var w = 0, h = 0
    for i in 0..<sizes.count {
        if sizes[i][0] < sizes[i][1] { sizes[i].swapAt(0, 1) }
        w = max(w, sizes[i][0])
        h = max(h, sizes[i][1])
    }
    return w*h
}