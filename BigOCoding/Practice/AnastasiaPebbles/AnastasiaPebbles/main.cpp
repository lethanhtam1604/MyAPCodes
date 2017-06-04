//
//  main.cpp
//  AnastasiaPebbles
//
//  Created by Thanh-Tam Le on 4/9/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int n, k;
    int res = 0;
    
    cin>>n>>k;
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        res++;
        while (temp > k) {
            temp = temp - k;
            res++;
        }
    }
    
    cout<<(res + 1)/2;

    return 0;
}
