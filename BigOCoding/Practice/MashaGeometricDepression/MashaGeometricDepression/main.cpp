//
//  main.cpp
//  AnastasiaPebbles
//
//  Created by Thanh-Tam Le on 4/9/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    long long b1, q, l, m;
    cin>>b1>>q>>l>>m;
    vector<int> v;
    
    int res = 0;
    for (int i = 0; i < m; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    long long previousValue = -1;
    int index = 0;
    
    while (1) {
        
        bool flag = false;
        for (int i = 0; i < m; i++) {
            if (b1 == v[i]) {
                flag = true;
                break;
            }
        }
        
        if (abs(b1) <= l && !flag) {
            res++;
        }
        else if (abs(b1) > l) {
            cout<<res;
            break;
        }
        
        previousValue = b1;
        b1 = b1*q;
        index++;
        
        if (index == 2) {
            if (b1 == -1 || q == -1) {
                if (abs(b1) == abs(previousValue) && res == 0) {
                    cout<<0;
                    break;
                }
                
                if (abs(b1) == abs(previousValue) && res != 0) {
                    cout<<"inf";
                    break;
                }
            }
            else {
                if (abs(b1) == abs(previousValue) && res == 0) {
                    cout<<0;
                    break;
                }
                
                if (abs(b1) == abs(previousValue) && res != 0 && flag == true) {
                    cout<<res;
                    break;
                }
                
                if (abs(b1) == abs(previousValue) && res != 0 && flag == false) {
                    cout<<"inf";
                    break;
                }
            }
        }
    }
    
    return 0;
}
