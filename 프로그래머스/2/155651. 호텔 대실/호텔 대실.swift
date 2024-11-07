import Foundation

func convert_time(_ str: String) -> Int {
    let str = str.components(separatedBy: [":"]).map { Int($0)! }
    return str[0] * 60 + str[1]
}

func solution(_ book_time:[[String]]) -> Int {
    let book_time = book_time.sorted { t1, t2 in return t1[0] < t2[0] }
    var isVisited = [Bool](repeating: false, count: book_time.count)
    
    let count = book_time.count
    var answer = 0
    for i in 0..<count {
        if isVisited[i] { continue }
        var end_time = convert_time(book_time[i][1]) + 10
        for j in 0..<count {
            if isVisited[j] { continue }
            let start_time = convert_time(book_time[j][0])
            if start_time < end_time { continue }
            end_time = convert_time(book_time[j][1]) + 10
            isVisited[j] = true
        }
        isVisited[i] = true
        answer += 1
        print(answer)
    }
    return answer
}
