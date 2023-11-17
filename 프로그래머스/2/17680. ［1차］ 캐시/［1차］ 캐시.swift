import Foundation

func solution(_ cacheSize: Int, _ cities: [String]) -> Int {
    var cache = [String]()
    var answer = 0
    
    cities.forEach { city in
        let lowercity = city.lowercased()
        let index = cache.firstIndex(of: lowercity)
        if index == nil { answer += 5; cache.append(lowercity); if cache.count > cacheSize { cache.removeFirst() } }
        else { answer += 1; cache.append(cache.remove(at: index!)) }
    }
    return answer
}