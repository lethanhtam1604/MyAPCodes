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
    
    set<long long> s;
    long long temp;
    set<long long>::iterator it;
    
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        for(int i = 0; i < n ; i++) {
            scanf("%lld", &temp);
            s.insert(temp);
        }
        
        for (int i = 0; i < m; i++) {
            scanf("%lld", &temp);
            it = s.find(temp);
            
            if (it == s.end()) {
                printf("NO\n");
            }
            else {
                printf("YES\n");
            }
            s.insert(temp);
        }
        
        s.clear();
    }
    
    return 0;
}
