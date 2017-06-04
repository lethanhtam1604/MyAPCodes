//
//  main.cpp
//  Bai01
//
//  Created by Thanh-Tam Le on 5/16/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <functional>
#include <map>

#define MAX 10

using namespace std;

struct Pair {
    int index;
    int value;
    int count = 0;
    
    Pair(int i, int v) {
        index = i;
        value = v;
    }
};

bool option(const Pair &x, const Pair &y) {
    return (int)x.value < (int)y.value;
}

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    int n;
    cin>>n;
    vector<Pair> pairs;
    int temp;
    
    vector<vector<int> > data(MAX);
    
    for (int i = 1; i <= n; i++) {
        cin>>temp;
        
        data[temp].push_back(i);
        pairs.push_back(Pair(i, temp));
    }
    
    for (int i = 1; i <= n; i++) {
        
        if (data[i].size() > 0) {
            
            int tao = 0;
            
            for (int j = 0; j < data[i].size(); j++) {
                
                if (tao <= data[i].size()) {
                    cout<<data[i][tao]<<" ";
                }
                
                
                for (int l = 0; l < data[i].size(); l++) {
                    if (l != tao) {
                        cout<<data[i][l]<<" ";
                    }
                }
                
                for (int k = 0; k <= n; k++) {
                    if (data[k].size() > 0) {
                        if (k != i) {
                            for (int j = 0; j < data[i].size(); j++) {
                                cout<<data[k][j]<<" ";
                            }
                        }
                    }
                }
                
                cout<<endl;
                
                tao++;
            }
        }
        
        
    }
    
    return 0;
}
