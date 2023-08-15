import Foundation

func solution(_ my_string:String, _ index_list:[Int]) -> String {
    var answer = String()
    let arr = Array(my_string)
    for i in index_list { answer.append(arr[i]) }
    return answer
}