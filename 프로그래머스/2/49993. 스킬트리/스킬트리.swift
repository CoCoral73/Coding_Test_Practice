import Foundation

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
    var answer = 0
    
    for tree in skill_trees {
        let filter = tree.filter { ch in
            return skill.contains(ch)
        }
        
        if filter.isEmpty || skill.contains(filter) && skill.first! == filter.first! {
            answer += 1
        }
    }
    return answer
}