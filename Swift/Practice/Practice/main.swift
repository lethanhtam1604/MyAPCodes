//
//  main.swift
//  Practice
//
//  Created by Thanh-Tam Le on 6/9/17.
//  Copyright © 2017 Tam. All rights reserved.
//

import Foundation

let n = Int(readLine()!)!

let arr = readLine()!.components(separatedBy: " ").map{ Int($0)! }

var positiveN = 0, negativeN = 0, zeroN = 0

for index in 0..<n {
    if arr[index] == 0 {
        zeroN += 1
    }
    else if arr[index] < 0 {
        negativeN += 1
    }
    else {
        positiveN += 1
    }
}


print(round(1000000*Double(1.0 * Double(positiveN)/Double(arr.count)))/1000000)
print(round(1000000*Double(1.0 * Double(negativeN)/Double(arr.count)))/1000000)
print(round(1000000*Double(1.0 * Double(zeroN)/Double(arr.count)))/1000000)
