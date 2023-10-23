import Foundation

func solution(_ n:Int) -> Int
{
    func count1(_ str:String) -> Int {
        return str.reduce(0) { $0 + Int(String($1))! }
    }
    let cnt1 = count1(String(n, radix: 2))
    var n = n + 1
    while true {
        let cnt2 = count1(String(n, radix: 2))
        if cnt1 == cnt2 { return n }
        n += 1
    }
}