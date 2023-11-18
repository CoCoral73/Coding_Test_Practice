import Foundation

func solution(_ str1:String, _ str2:String) -> Int {
    //자카드 유사도: 교집합 크기 / 합집합 크기, 둘 다 공집합일 경우 1
    let str1 = str1.lowercased(), str2 = str2.lowercased()
    var set1 = Dictionary<String, Int>(), set2 = Dictionary<String, Int>()
    
    for i in 0..<(str1.count-1) {
        let idx1 = str1.index(str1.startIndex, offsetBy: i)
        let idx2 = str1.index(after: idx1)
        if !str1[idx1].isLetter || !str1[idx2].isLetter { continue }
        let word = String(str1[idx1...idx2])
        if set1[word] == nil { set1.updateValue(1, forKey: word) }
        else { set1[word]! += 1 }
    }
    
    for i in 0..<(str2.count-1) {
        let idx1 = str2.index(str2.startIndex, offsetBy: i)
        let idx2 = str2.index(after: idx1)
        if !str2[idx1].isLetter || !str2[idx2].isLetter { continue }
        let word = String(str2[idx1...idx2])
        if set2[word] == nil { set2.updateValue(1, forKey: word) }
        else { set2[word]! += 1 }
    }
    
    var x = 0, y = 0
    let set = Set(set1.keys).union(set2.keys)
    set.forEach { word in
        let cnt1 = set1[word] ?? 0
        let cnt2 = set2[word] ?? 0
        x += min(cnt1, cnt2)
        y += max(cnt1, cnt2)
    }
    
    return y == 0 ? 65536 : Int((Double(x) / Double(y))*65536)
}