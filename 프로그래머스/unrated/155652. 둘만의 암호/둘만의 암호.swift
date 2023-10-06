import Foundation

func solution(_ s:String, _ skip:String, _ index:Int) -> String {
    let alphabet = Array("abcdefghijklmnopqrstuvwxyz")
    var isSkip = Array(repeating: false, count: 26)
    
    skip.forEach {
        let idx = Int($0.asciiValue! - Character("a").asciiValue!)
        isSkip[idx] = true
    }
    
    return String(s.map {
        var idx = Int($0.asciiValue! - Character("a").asciiValue!)
        var i = 1
        while i <= index {
            idx = (idx + 1) % 26
            if !isSkip[idx] { i += 1 }
        }
        return alphabet[idx]
    })
}