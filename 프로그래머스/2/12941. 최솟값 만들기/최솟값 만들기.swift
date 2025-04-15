import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int
{
    return zip(A.sorted(by: >), B.sorted(by: <)).reduce(0) { return $0 + $1.0*$1.1 }
}