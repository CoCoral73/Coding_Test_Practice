import Foundation

func solution(_ points:[[Int]], _ routes:[[Int]]) -> Int {
    let points = [[0,0]] + points
    var robots = routes.map { points[$0[0]] }   //로봇의 현재 좌표
    var indexs = [Int](repeating: 1, count: routes.count)   //각 로봇의 목적지
    var numOfRobots = routes.count
    
    var answer = 0
    while numOfRobots > 0 {
        var coordinate = [[Int]:Int]()
        //충돌 횟수 카운트
        for i in 0..<robots.count {
            let rc = robots[i]
            if rc == [-1, -1] { continue }
            coordinate.updateValue((coordinate[rc] ?? 0) + 1, forKey: rc)
        }
        answer += coordinate.values.filter { $0 > 1 }.count
        
        //로봇 이동
        for i in 0..<robots.count {
            if robots[i] == [-1, -1] { continue }
            
            if robots[i] == points[routes[i][indexs[i]]] {
                indexs[i] += 1
            }
            
            if indexs[i] == routes[i].count {
                robots[i] = [-1, -1]
                numOfRobots -= 1
                continue
            }
            
            let src = robots[i]
            let dest = points[routes[i][indexs[i]]]
            if src[0] == dest[0] {  //r 좌표 같을 때
                if src[1] < dest[1] { robots[i] = [src[0], src[1] + 1] }
                else { robots[i] = [src[0], src[1] - 1] }
            } else {    //r 좌표 다를 때
                if src[0] < dest[0] { robots[i] = [src[0] + 1, src[1]] }
                else { robots[i] = [src[0] - 1, src[1]] }
            }
        }
    }
    
    return answer
}