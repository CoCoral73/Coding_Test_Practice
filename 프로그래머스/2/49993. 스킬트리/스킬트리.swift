import Foundation

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
    let skill_set = Set(skill)
    var answer: Int = 0
    
    for tree in skill_trees {
        let filtered = tree.filter { skill_set.contains($0) }
        if skill.prefix(filtered.count) == filtered {
            answer += 1        
        }
    }
    
    return answer
}