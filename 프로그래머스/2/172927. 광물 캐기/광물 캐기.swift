import Foundation

func solution(_ picks:[Int], _ minerals:[String]) -> Int {
    var picks = picks
    let minerals = minerals[0..<min(minerals.count, picks.reduce(0) { $0 + $1 * 5 })]
    var minerals_5 = [[String]]()
    var startIndex: Int = 0
    
    while startIndex < minerals.count {
        let endIndex = min(startIndex+5, minerals.count)
        minerals_5.append([String](minerals[startIndex..<endIndex]))
        startIndex = endIndex
    }
    
    minerals_5.sort(by: {
        let dia1 = $0.filter { $0 == "diamond" }.count, dia2 = $1.filter { $0 == "diamond" }.count
        let iron1 = $0.filter { $0 == "iron" }.count, iron2 = $1.filter { $0 == "iron" }.count
        
        if dia1 != dia2 { return dia1 > dia2 }
        if iron1 != iron2 { return iron1 > iron2 }
        return dia1 + iron1 < dia2 + iron2
        
    })
    
    var pick = 0, next = 0, answer = 0
    while pick < 3 && next < minerals_5.count {
        if picks[pick] == 0 { pick += 1; continue }
        
        for m in minerals_5[next] {
            if pick == 0 {
                answer += 1
            } else if pick == 1 {
                if m == "diamond" {
                    answer += 5
                } else {
                    answer += 1
                }
            } else {
                if m == "diamond" {
                    answer += 25
                } else if m == "iron" {
                    answer += 5
                } else {
                    answer += 1
                }
            }
        }
        
        next += 1
        picks[pick] -= 1
    }
    return answer
}