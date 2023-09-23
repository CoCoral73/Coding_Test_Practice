import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    let price = Int64(price), money = Int64(money), count = Int64(count)
    var answer = (1...count).reduce(0, {$0 + $1*price})
    return money-answer >= 0 ? 0 : answer-money
}