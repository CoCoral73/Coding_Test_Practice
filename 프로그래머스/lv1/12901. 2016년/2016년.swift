func solution(_ a:Int, _ b:Int) -> String {
    let answer = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"]
    let month = [0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]
    return answer[(month[a-1] + b - 1) % 7]
}