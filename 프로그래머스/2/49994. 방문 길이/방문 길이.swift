import Foundation

func solution(_ dirs:String) -> Int {
    let dirs = dirs.map { $0 }
    var street: Set<[Int]> = []
    
    var now: (Int, Int) = (0, 0)
    for dir in dirs {
        let next: (Int, Int)
        switch dir {
            case "U":
                next = (now.0, now.1 + 1)
            case "D":
                next = (now.0, now.1 - 1)
            case "R":
                next = (now.0 + 1, now.1)
            default:
                next = (now.0 - 1, now.1)
        }
        
        if -5...5 ~= next.0 && -5...5 ~= next.1 {
            if now == next { continue }
            street.insert([now.0, now.1, next.0, next.1])
            street.insert([next.0, next.1, now.0, now.1])
            now = next
        }
    }
    
    return street.count / 2
}