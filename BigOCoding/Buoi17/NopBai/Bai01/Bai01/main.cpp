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

#define MAX 200005

using namespace std;

struct Pair {
    int u;
    int v;
    
    Pair(int a, int b) {
        u = a;
        v = b;
    }
};

vector<int> parent;

int findSet(int u) {
    while(u != parent[u])
        u = parent[u];
    return u;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    parent[vp] = up;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    int t, n;
    scanf("%d", &t);
    
    int count[MAX];
    
    int k = 1, u, v, next = 1;
    string x, y;
    

    while (t--) {
        
        scanf("%d", &n);
        
        parent = vector<int>(n+2);
        
        vector<Pair> pairs;
        map<string, int> data;
        
        for (int i = 1; i <= n; i++) {
            
            cin>>x>>y;
            
            if(data.find(x) == data.end()) {
                data[x] = k++;
            }
            
            if(data.find(y) == data.end()) {
                data[y] = k++;
            }
            
            u = data[x]; v = data[y];
            
            
            pairs.push_back(Pair(u, v));
        }
        
        memset(count, 0, sizeof(count));
        
        for (int i = 1; i <= k - 1; i++) {
            parent[i] = i;
        }
        
        
        int root;

        for (int i = 0; i < pairs.size(); i++) {
            
            int a = findSet(pairs[i].u);
            int b = findSet(pairs[i].v);
            
            if (a != b) {
                int lon = findSet(pairs[i].v);
                unionSet(pairs[i].u, pairs[i].v);
                
                root = findSet(pairs[i].u);
                
                if (count[root] == 0) {
                    count[root] += 1;
                }
                
                if (count[lon] == 0) {
                    count[root] += 1;
                }
                else {
                    count[root] += count[lon];
                }
                
                
                printf("%d\n", count[root]);
            }
            else {
                
                if (count[a] == 0) {
                    count[a]++;
                }
                
                printf("%d\n", count[a]);
            }
        }
        
        parent.clear();
        k = 1; next = 1;
        pairs.clear();
        data.clear();
    }
    
    return 0;
}
