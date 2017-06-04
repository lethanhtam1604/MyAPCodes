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

#define MAX 50005

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
    
    //    int root = 0, child = 0;
    //    if (up >= vp) {
    //        root = up;
    //        child = vp;
    //    }
    //    else {
    //        root = vp;
    //        child = up;
    //    }
    parent[vp] = up;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    
    int count[MAX];
    
    int n, m, u, v;
    string x, y;
    
    scanf("%d %d", &n, &m);
    
    int r = 0;
    int t = 0;
    
    while (n != 0 & m != 0) {
        t++;
        
        parent = vector<int>(n+2);
        
        vector<Pair> pairs;
        
        
        memset(count, 0, sizeof(count));
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        int root;
        
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &u, &v);
            unionSet(u, v);
        }
        
        for (int i = 1; i <= n; i++) {
            root = findSet(i);
            if (root != i) {
                count[root] += 1;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (count[i] != 0) {
                r++;
            }
            else {
                root = findSet(i);
                
                if (count[root] == 0) {
                    r++;
                }
            }
        }
        
        cout<<"Case "<<t<<": "<<r<<endl;
        scanf("%d %d", &n, &m);
        r = 0;
    }
    
    return 0;
}
