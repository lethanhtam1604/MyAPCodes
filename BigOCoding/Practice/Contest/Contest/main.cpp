//
//  main.cpp
//  GukiZContest
//
//  Created by Thanh-Tam Le on 4/10/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;


int main() {
    
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> v;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    int left = -1, right = -1;
    int leftSum = 0, rightSum = 0;
    
    for (int i = m; i < n; i++) {
        rightSum += 10;
        if (v[i] != 0 && v[i] <= k) {
            right = i;
            break;
        }
    }
    
    for (int i = m - 2; i >= 0; i--) {
        leftSum += 10;
        if (v[i] != 0 && v[i] <= k) {
            left = i;
            break;
        }
    }
    
    if (right != -1 && left != -1) {
        
        if(rightSum <= leftSum) {
            cout<<rightSum;
        }
        else {
            cout<<leftSum;
        }
    }
    else if (left != -1) {
        cout<<leftSum;
    }
    else {
        cout<<rightSum;
    }
    
    return 0;
}
