func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var answer = [String]()
    for i in 0..<n {
        var line1 = String(arr1[i], radix: 2)
        line1 = line1.count == n ? line1 : String(repeating: "0", count: n-line1.count) + line1
        var line2 = String(arr2[i], radix: 2)
        line2 = line2.count == n ? line2 : String(repeating: "0", count: n-line2.count) + line2
        answer.append(zip(line1, line2).reduce("") { return $0 + (($1.0 == "0" && $1.1 == "0") ? String(" ") : String("#")) })
        
    }
    return answer
}