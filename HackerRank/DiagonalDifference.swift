//
//  main.swift
//  Practice
//
//  Created by Thanh-Tam Le on 6/9/17.
//  Copyright © 2017 Tam. All rights reserved.
//

import Foundation

let n = Int(readLine()!)!

var arr: [[Int]] = []

for _ in 0..<n {
    arr.append(readLine()!.components(separatedBy: " ").map{ Int($0)! })
}

var sum1 = 0, sum2 = 0

for index in 0..<n {
    sum1 += arr[index][index]
    sum2 += arr[index][n - index - 1]
}

print(abs(sum1 - sum2))
