import Foundation

func solution(_ my_string:String, _ n:Int) -> String {
    return String(my_string[my_string.index(my_string.endIndex, offsetBy: -n)..<my_string.endIndex])
}