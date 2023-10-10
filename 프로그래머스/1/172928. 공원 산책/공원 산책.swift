import Foundation

func solution(_ park:[String], _ routes:[String]) -> [Int] {
    var r = 0, c = 0
    var flag = false;
    for i in 0..<park.count {
        for j in 0..<park[i].count {
            if park[i][park[i].index(park[i].startIndex, offsetBy: j)] == "S" {
                r = i; c = j
                flag = true
                break
            }
        }
        if flag { break }
    }
    routes.forEach {
        let op = $0.first, n = Int($0.suffix(1))!
        flag = true;
        if op == "N" {
            for i in 1...n {
                if r - i < 0 { flag = false; break; }
                if park[r-i][park[0].index(park[0].startIndex, offsetBy: c)] == "X" { flag = false; break; }
            }
            if flag { r -= n }
        }
        else if op == "E" {
            for i in 1...n {
                if c + i >= park[0].count { flag = false; break; }
                if park[r][park[0].index(park[0].startIndex, offsetBy: c+i)] == "X" { flag = false; break; }
            }
            if flag { c += n }
        }
        else if op == "S" {
            for i in 1...n {
                if r + i >= park.count { flag = false; break; }
                if park[r+i][park[0].index(park[0].startIndex, offsetBy: c)] == "X" { flag = false; break; }
            }
            if flag { r += n }
        }
        else if op == "W" {
            for i in 1...n {
                if c - i < 0 { flag = false; break; }
                if park[r][park[0].index(park[0].startIndex, offsetBy: c-i)] == "X" { flag = false; break; }
            }
            if flag { c -= n }
        }
    }
    
    return [r, c]
}