//
//  main.cpp
//  Bai01
//
//  Created by Thanh-Tam Le on 4/22/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <stdio.h>

using namespace std;

int BS_first(vector<int> &a, int left, int right, int x) {
    if(right >= left) {
        
        int mid = left + (right -left)/2;
        if ((mid == 0 || x > a[mid - 1]) && a[mid] == x)
            return mid;
        else if (x > a[mid])
            return BS_first(a, (mid + 1), right, x);
        else
            return BS_first(a, left, mid - 1, x);
    }
    
    return  -1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    #endif
    
    int n = -1, q = -1;
    vector<int> v;
    
    int testCase = 1;
    
    scanf("%d %d", &n, &q);
    
    
    while (n != 0 && q != 0) {
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            v.push_back(temp);
        }
        
        sort(v.begin(), v.end());
        
        printf("CASE# %d:\n", testCase);
        testCase++;
        
        for(int i = 0; i < q; i++) {
            int temp;
            scanf("%d", &temp);
            
            int index = BS_first(v, 0, n - 1, temp);
    
            if (index != -1) {
                printf("%d found at %d\n", temp, index + 1);
            }
            else {
                printf("%d not found\n", temp);
            }
        }
        
        v.clear();
        
        scanf("%d %d", &n, &q);
    }
    return 0;
}
