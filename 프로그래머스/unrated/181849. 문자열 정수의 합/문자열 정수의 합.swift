import Foundation

func solution(_ num_str:String) -> Int {
    return num_str.reduce(0) { $0 + Int(String($1))! }
}