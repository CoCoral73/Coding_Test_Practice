import Foundation

func solution(_ n_str:String) -> String {
    return String(n_str[n_str.firstIndex(where: { $0 != "0" })!...])
}