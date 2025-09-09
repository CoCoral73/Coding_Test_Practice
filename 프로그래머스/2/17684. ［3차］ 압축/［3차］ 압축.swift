import Foundation 

func solution(_ msg:String) -> [Int] {
    let msg = msg.map { String($0) }
    let alphabet = (65...90).map { String(UnicodeScalar($0)!) }
    var dict: [String: Int] = [:], lastIndex = 27, maxLen = 1
    var answer: [Int] = []
    
    for i in 0..<26 {
        dict[alphabet[i]] = i + 1
    }
    
    var start = 0
    while start < msg.count {
        for end in stride(from: min(start + maxLen - 1, msg.count - 1), through: start, by: -1) {
            let word = msg[start...end].joined()
            if let index = dict[word] {
                answer.append(index)
                
                if end + 1 != msg.count {
                    let next = word + msg[end + 1]
                    dict[next] = lastIndex
                    lastIndex += 1
                }
                maxLen = max(maxLen, end - start + 2)
                start = end + 1
                break
            }
        }
    }
    
    return answer
}