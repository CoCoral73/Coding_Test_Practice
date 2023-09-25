func solution(_ strings:[String], _ n:Int) -> [String] {
    return strings.sorted { (str1, str2) in
        let index = str1.index(str1.startIndex, offsetBy: n)
        return str1[index] == str2[index] ? str1 < str2 : str1[index] < str2[index]
    }
}