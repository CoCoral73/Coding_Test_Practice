import Foundation

func getGCD(_ a: Int64, _ b: Int64) -> Int64 {
    return b == 0 ? a : getGCD(b, a%b)
}

func solution(_ w:Int, _ h:Int) -> Int64{
    var w = Int64(w), h = Int64(h)
    var answer:Int64 = w*h
    var gcd = getGCD(w, h)
    var ww = w / gcd, hh = h / gcd
    
    var unit = ww * hh - (ww - 1) * (hh - 1)
    
    return answer - gcd*unit
}