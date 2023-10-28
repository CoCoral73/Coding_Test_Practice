import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    var width = brown + yellow
    var height = 1
    
    while true {
        if (brown + yellow) % width != 0 { width -= 1; continue }
        height = (brown + yellow) / width
        if 2*width + 2*height - 4 == brown { return [width, height] }
        width -= 1
    }
}