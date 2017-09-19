//
//  main.swift
//  Practice
//
//  Created by Thanh-Tam Le on 6/9/17.
//  Copyright © 2017 Tam. All rights reserved.
//

import Foundation

//let n = Int(readLine()!)!
//
//let arr = readLine()!.components(separatedBy: " ").map{ Int($0)! }
//
//var positiveN = 0, negativeN = 0, zeroN = 0
//
//for index in 0..<n {
//    if arr[index] == 0 {
//        zeroN += 1
//    }
//    else if arr[index] < 0 {
//        negativeN += 1
//    }
//    else {
//        positiveN += 1
//    }
//}
//
//
//print(round(1000000*Double(1.0 * Double(positiveN)/Double(arr.count)))/1000000)
//print(round(1000000*Double(1.0 * Double(negativeN)/Double(arr.count)))/1000000)
//print(round(1000000*Double(1.0 * Double(zeroN)/Double(arr.count)))/1000000)


let array = [4, 6, 1, 2, 8, 10, 9]

func bubbleSort(_ array: [Int]) -> [Int] {

    var a = array

    for i in 0..<a.count - 1 {
        for j in 0..<a.count - i - 1 {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1])
            }
        }
    }

    return a
}

func selectionSort(_ array: [Int]) -> [Int] {

    var a = array

    for i in 0..<a.count - 1 {

        var lowest = i

        for j in i + 1..<a.count{
            if (a[lowest] > a[j]) {
                lowest = j
            }
        }

        if lowest != i {
            swap(&a[i], &a[lowest])
        }
    }

    return a
}

func insertionSort(_ array: [Int]) -> [Int] {

    var a = array

    for i in 1..<a.count {

        var y = i

        while y > 0 && a[y] < a[y - 1] {
            swap(&a[y], &a[y-1])
            y -= 1
        }
    }
    
    return a
}

func printArray(_ array: [Int]) {

    for i in 0..<array.count {
        print(array[i])
    }
}

print(bubbleSort(array))
print(selectionSort(array))
print(insertionSort(array))



