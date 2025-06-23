import Foundation

func solution(_ str1:String, _ str2:String) -> Int {
    //J(A, B) = n(A ∩ B) / n(A ∪ B) *A, B 둘다 공집합일 경우 1
    let str1 = str1.lowercased.map { $0 }, str2 = str2.lowercased.map { $0 }
    var A = [String:Int](), B = A
    
    for i in 0..<(str1.count-1) {
        if str1[i].isLetter && str1[i+1].isLetter {
            let word = "\(str1[i])\(str1[i+1])"
            if let _ = A[word] {
                A[word]! += 1
            } else {
                A[word] = 1
            }
        }
    }
    
    for i in 0..<(str2.count-1) {
        if str2[i].isLetter && str2[i+1].isLetter {
            let word = "\(str2[i])\(str2[i+1])"
            if let _ = B[word] {
                B[word]! += 1
            } else {
                B[word] = 1
            }
        }
    }
    
    var intersect: Int = 0, union: Int = 0
    for key in Set(A.keys).union(Set(B.keys)) {
        intersect += min(A[key] ?? 0, B[key] ?? 0)
        union += max(A[key] ?? 0, B[key] ?? 0)
    }
    
    if union == 0 { return 65536 }
    return Int(Double(intersect) / Double(union) * 65536)
}