import Foundation

func solution(_ data:[[Int]], _ col:Int, _ row_begin:Int, _ row_end:Int) -> Int {
    let data = data.sorted(by: { arr1, arr2 in
        if arr1[col-1] == arr2[col-1] {
            return arr1[0] > arr2[0]
        } else {
            return arr1[col-1] < arr2[col-1]
        }
    })
    
    func get_Si(_ i: Int) -> Int {
        return data[i-1].reduce(0) { $0 + $1 % i }
    }
    
    var answer = 0
    for i in row_begin...row_end {
        answer ^= get_Si(i)
    }
    
    return answer
}