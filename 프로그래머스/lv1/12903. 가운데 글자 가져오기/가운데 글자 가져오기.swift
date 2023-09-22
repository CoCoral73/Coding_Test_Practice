func solution(_ s:String) -> String {
    let s = Array(s)
    return s.count % 2 == 1 ? String(s[s.count/2]) : String(s[s.count/2-1...s.count/2])
}