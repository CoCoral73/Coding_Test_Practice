import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var stage = [(Int, Int)](repeating: (0,0), count: N+1)
    var rate = [Double](repeating: 0, count: N+1)
    var answer = (1...N).map { $0 }
    
    stages.forEach {
        for i in 1...min($0, N) { stage[i].1 += 1 }
        if $0 <= N { stage[$0].0 += 1 }
    }
    
    stage.enumerated().forEach {
        rate[$0.offset] = $0.element.1 == 0 ? 0 : Double($0.element.0) / Double($0.element.1)
    }
    answer.sort(by: {
        if rate[$0] == rate[$1] { return $0 < $1 }
        else { return rate[$0] > rate[$1] }
    })
    return answer
}