import Foundation

//빠른 입출력
class FileIO {
    @inline(__always) private var buffer: [UInt8] = Array(FileHandle.standardInput.readDataToEndOfFile()) + [0], byteIdx = 0
    
    @inline(__always) private func readByte() -> UInt8 {
        defer { byteIdx += 1 }
        return buffer.withUnsafeBufferPointer { $0[byteIdx] }
    }
    
    @inline(__always) func readInt() -> Int {
        var number = 0, byte = readByte(), isNegative = false
        while byte == 10 || byte == 32 { byte = readByte() }
        if byte == 45 { byte = readByte(); isNegative = true }
        while 48...57 ~= byte { number = number * 10 + Int(byte - 48); byte = readByte() }
        return number * (isNegative ? -1 : 1)
    }
    
    @inline(__always) func readStirngSum() -> Int {
        var byte = readByte()
        while byte == 10 || byte == 32 { byte = readByte() }
        var sum = Int(byte)
        while byte != 10 && byte != 32 && byte != 0 { byte = readByte(); sum += Int(byte) }
        return sum - Int(byte)
    }
    
    @inline(__always) private func write(_ output: String) {
        FileHandle.standardOutput.write(output.data(using: .utf8)!)
    }
}

let fIO = FileIO()
let M = fIO.readInt()
var S = 0, result = ""

for _ in 0..<M {
    switch fIO.readStirngSum() {
    case 297:
        let x = fIO.readInt()
        S |= 1 << (x-1)
    case 654:
        let x = fIO.readInt()
        S &= ~(1 << (x-1))
    case 510:
        let x = fIO.readInt()
        result += (S & (1 << (x-1))) > 0 ? "1\n" : "0\n"
    case 642:
        let x = fIO.readInt()
        S ^= 1 << (x-1)
    case 313:
        S = 1048575
    default:
        S = 0
    }
}
print(result)