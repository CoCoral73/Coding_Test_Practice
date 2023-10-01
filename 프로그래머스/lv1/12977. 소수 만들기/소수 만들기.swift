import Foundation

func solution(_ nums:[Int]) -> Int {
    let nums = nums.sorted()
    let N = nums.count, MAX = nums[N-1]+nums[N-2]+nums[N-3]
    var isPrime = [Bool](repeating: true, count: MAX+1)
    isPrime[0] = false
    isPrime[1] = false
    for i in 2..<MAX {
        if !isPrime[i] { continue }
        for j in stride(from: 2*i, through: MAX, by: i) { isPrime[j] = false }
    }
    
    var answer = 0, sum = 0
    func dfs(_ depth:Int, _ index:Int) {
        if depth == 3 {
            if isPrime[sum] { answer += 1 }
            return
        }
        for i in index..<N {
            sum += nums[i]
            dfs(depth+1, i+1)
            sum -= nums[i]
        }
    }
    dfs(0, 0)
    return answer
}