import Foundation

func solution(_ wallpaper:[String]) -> [Int] {
    var lux = wallpaper.count, luy = wallpaper[0].count
    var rdx = 0, rdy = 0
    
    wallpaper.enumerated().forEach {
        let line = Array($0.element)
        if line.contains("#") { lux = min(lux, $0.offset); rdx = max(rdx, $0.offset + 1) }
        luy = min(luy, line.firstIndex(of: "#") ?? luy)
        rdy = max(rdy, (line.lastIndex(of: "#") ?? -1) + 1)
        
    }
    return [lux, luy, rdx, rdy]
}