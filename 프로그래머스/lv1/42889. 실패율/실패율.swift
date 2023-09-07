import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var arr = [(Int, Int)](repeating: (0, 0), count: N)
    var rate = [Double]()
    var answer = [Int]()

    stages.forEach {
        for i in 0..<($0-1) { arr[i].1 += 1 }
        if $0-1 < N {
            arr[$0-1].0 += 1;
            arr[$0-1].1 += 1;
        }
    }
    
    rate = arr.map { $0.1 == 0 ? 0 : Double($0.0) / Double($0.1) }
    
    for _ in 0..<N {
        let index = rate.firstIndex(of: rate.max()!)!
        answer.append(index+1)
        rate[index] = -1
    }
    
    return answer
}