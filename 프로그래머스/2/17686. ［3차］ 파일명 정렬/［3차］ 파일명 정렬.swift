func findHeadAndNumber(_ name: String) -> (String, Int) {
    let name = Array(name)
    let first = name.firstIndex { $0.isNumber }!
    let head = String(name[0..<first]).lowercased()
    var last = first
    
    while last < name.count, name[last].isNumber { last += 1 }
    let number = Int(String(name[first..<last]))!
    return (head, number)
}

func solution(_ files:[String]) -> [String] {
    return files.sorted(by: { (file1, file2) in 
        let info1 = findHeadAndNumber(file1)
        let info2 = findHeadAndNumber(file2)
        
        if info1.0 == info2.0 { return info1.1 < info2.1 }
        else { return info1.0 < info2.0 }
    })
}