import Foundation

func solution(_ friends:[String], _ gifts:[String]) -> Int {
    var indexs = [String: Int]()
    for i in 0..<friends.count {
        indexs.updateValue(i, forKey: friends[i])
    }
    
    //giveNtake[give][take]: give가 take한테 준 선물의 수
    var giveNtake = [[Int]](repeating: [Int](repeating: 0, count: friends.count), count: friends.count)
    var valueOfGift = [Int](repeating: 0, count: friends.count)
    gifts.forEach { str in
        let names = str.components(separatedBy: [" "])
        let give = indexs[names[0]]!, take = indexs[names[1]]!
        giveNtake[give][take] += 1
        valueOfGift[give] += 1
        valueOfGift[take] -= 1
    }
    
    var willTake = [Int](repeating: 0, count: friends.count)
    for i in 0..<friends.count {
        for j in (i + 1)..<friends.count {
            let f1 = indexs[friends[i]]!, f2 = indexs[friends[j]]!
            let iToj = giveNtake[f1][f2]
            let jToi = giveNtake[f2][f1]
            
            if iToj != jToi {
                willTake[iToj < jToi ? j : i] += 1
            }
            else {
                let v1 = valueOfGift[f1], v2 = valueOfGift[f2]
                if v1 != v2 {
                    willTake[v1 < v2 ? f2 : f1] += 1
                }
            }
        }
    }

    return willTake.max()!
}