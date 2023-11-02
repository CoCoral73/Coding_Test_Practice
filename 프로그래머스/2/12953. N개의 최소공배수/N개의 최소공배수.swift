import Foundation

func solution(_ arr:[Int]) -> Int {
    func GCD(_ a:Int, _ b:Int) -> Int {
        if (b == 0) { return a }
        else { return GCD(b, a % b) }
    }
    
    var arr = arr
    while arr.count > 1 {
        let top = arr.removeFirst()
        arr[0] = (top * arr.first!) / GCD(top, arr.first!)
    }
    return arr.first!
}