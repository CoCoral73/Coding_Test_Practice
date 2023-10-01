func solution(_ n:Int) -> Int {
    var isPrime = [Bool](repeating: true, count: n+1)
    isPrime[0] = false
    isPrime[1] = false
    for i in 2..<n {
        if !isPrime[i] { continue }
        for j in stride(from: 2*i, through: n, by: i) { isPrime[j] = false }
    }
    
    return isPrime.filter { $0 }.count
}