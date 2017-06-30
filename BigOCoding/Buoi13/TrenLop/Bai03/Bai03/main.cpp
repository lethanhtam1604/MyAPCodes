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

int main () {
    
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    int n;
    scanf("%d", &n);
    
    set <long long> s;
    set <long long> :: iterator it;

    long long res = 1e17;
    long long x;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        
        it = s.upper_bound(x);
        
        if (it != s.end())
            res = min(res , *it - x);
        
        s.insert(x);
    }
    
    printf("%lld", res);
    
    return 0; 
}
