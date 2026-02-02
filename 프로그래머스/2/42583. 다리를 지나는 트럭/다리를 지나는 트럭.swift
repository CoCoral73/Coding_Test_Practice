import Foundation

func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var answer: Int = 0
    var bridge = [Int](repeating: 0, count: bridge_length) 
    var current_count: Int = 0, current_weight: Int = 0, index: Int = 0
    
    while !(index == truck_weights.count && current_count == 0) {
        let front = bridge.removeFirst()
        if front > 0 {
            current_count -= 1
            current_weight -= front
        }

        if index < truck_weights.count && current_count < bridge_length && current_weight + truck_weights[index] <= weight {
            bridge.append(truck_weights[index])
            current_count += 1
            current_weight += truck_weights[index]
            index += 1
        } else {
            bridge.append(0)
        }
        
        answer += 1
    }

    return answer
}