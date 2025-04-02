import Foundation

func getGCD(_ a: Int, _ b: Int) -> Int {
    if b == 0 { return a }
    return getGCD(b, a % b)
}

func solution(_ arrayA:[Int], _ arrayB:[Int]) -> Int {
    var gcdA: Int = arrayA.first!
    var gcdB: Int = arrayB.first!
    
    for i in stride(from: 1, to: arrayA.count, by: 1) {
        gcdA = getGCD(arrayA[i], gcdA)
        gcdB = getGCD(arrayB[i], gcdB)
    }
    
    var aA: Int = arrayB.filter { $0 % gcdA == 0 }.count == 0 ? gcdA : 0
    var aB: Int = arrayA.filter { $0 % gcdB == 0 }.count == 0 ? gcdB : 0
    
    return max(aA, aB)
}