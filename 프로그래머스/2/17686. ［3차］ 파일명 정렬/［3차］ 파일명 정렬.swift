import Foundation

func solution(_ files:[String]) -> [String] {
    var files = files
    files.sort(by: { (str1, str2) in
        let idx11 = str1.firstIndex(where: { $0.isNumber })!, idx21 = str2.firstIndex(where: { $0.isNumber })!
        var idx12 = idx11, idx22 = idx21
        
        while idx12 < str1.endIndex && str1[idx12].isNumber { idx12 = str1.index(after: idx12) }
        while idx22 < str2.endIndex && str2[idx22].isNumber { idx22 = str2.index(after: idx22) }
        
        let head1 = str1[str1.startIndex..<idx11].lowercased(), head2 = str2[str2.startIndex..<idx21].lowercased()
        let number1 = Int(str1[idx11..<idx12])!, number2 = Int(str2[idx21..<idx22])!
        
        if head1 == head2 { return number1 < number2 }
        else { return head1 < head2 }
    })
    
    return files
}