func solution(_ s:String, _ n:Int) -> String {
    var s = Array(s)
    for i in 0..<s.count {
        if s[i].isWhitespace { continue }
        var ascii = s[i].asciiValue! + UInt8(n)
        if s[i].isUppercase {
            ascii = ascii > Character("Z").asciiValue! ? ascii - 26 : ascii
        }
        else {
            ascii = ascii > Character("z").asciiValue! ? ascii - 26 : ascii
        }
        s[i] = Character(UnicodeScalar(ascii))
    }
    return String(s)
}