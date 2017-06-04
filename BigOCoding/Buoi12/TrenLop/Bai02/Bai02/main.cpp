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

struct Money {
    int sum;
};

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

int BS_last(vector<int> &a, int left, int right, int x, int n) {
    
    if(right >= left) {
        int mid = left + (right - left)/2;
        if ((mid == n - 1 || x < a[mid + 1]) && a[mid] == x)
            return mid;
        else if (x < a[mid])
            return BS_last(a, left, mid - 1, x, n);
        else
            return BS_last(a, mid + 1, right, x, n);
    }
    
    return  -1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    #endif
    
    int t;
    scanf("%d", &t);
    vector<int> v;
    vector<int> pairs;
    
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        for(int i = 0; i < n ; i++) {
            int temp;
            scanf("%d", &temp);
            v.push_back(temp);
        }
        
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                pairs.push_back(v[i] + v[j]);
                
            }
        }
        
        sort(pairs.begin(), pairs.end());
        
        int first = BS_first(pairs, 0, (int)pairs.size() - 1, m);
        int last = BS_last(pairs, 0, (int)pairs.size() - 1, m, (int)pairs.size());
        
        if (first == -1) {
            printf("%d\n", 0);
        }
        else {
            if (first == last) {
                printf("%d\n", 1);
            }
            else {
                printf("%d\n", last - first + 1);
            }
        }
        
        v.clear();
        pairs.clear();
    }
    
    return 0;
}
