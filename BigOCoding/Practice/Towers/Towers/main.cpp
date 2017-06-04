//
//  main.cpp
//  PrinterQueue
//
//  Created by Thanh-Tam Le on 4/12/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

struct Tower {
    
    int tower;
    int height;
    
    Tower(int a = 0, int b = 1) {
        tower = a;
        height = b;
    }
};

int main() {
    
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int n;
    scanf("%d", &n);
    
    vector<Tower> v;
    
    int max = 1;
    
    while (n--) {
        
        int a;
        scanf("%d ", &a);
        
        bool flag = false;
        for(int i = 0; i < v.size(); i++) {
            if (v[i].tower == a) {
                flag = true;
                v[i].height += 1;
                
                if (max < v[i].height) {
                    max = v[i].height;
                }
                
                break;
            }
        }
        
        if (!flag) {
            v.push_back(Tower(a, 1));
        }
        
    }
    
    cout<<max<<" "<<v.size();
    
    return 0;
}
