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

int n;

int main () {
    
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    ios :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    set <long long> S;

    long long res = 1e17 + 1000;
    
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        
        set <long long> :: iterator it = S.upper_bound(x);
        
        printf("%lld\n", *it);
        if (it != S.end())
            res = min(res , *it - x);
        
        S.insert(x);
    }
    
    cout << res;
    return 0; 
}
