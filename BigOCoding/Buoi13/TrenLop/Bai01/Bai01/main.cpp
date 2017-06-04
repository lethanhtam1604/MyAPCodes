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
#include <set>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    int t;
    scanf("%d", &t);
    set<int> s;
    int temp;

    while(t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        
        for(int i = 0; i < n ; i++) {
            scanf("%d", &temp);
            s.insert(temp);
        }
        
        if (s.size() == x) {
            printf("Good\n");
        }
        else if (s.size() > x) {
            printf("Average\n");
            
        }
        else {
            printf("Bad\n");
        }
        
        s.clear();
    }
    
    return 0;
}
