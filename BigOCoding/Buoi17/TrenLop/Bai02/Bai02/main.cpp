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

#define MAX 30005

using namespace std;

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
    
    int t;
    scanf("%d", &t);

    int n, m;
    int count[MAX];
    int root;
    while (t--) {
        
        scanf("%d %d", &n, &m);
        
        parent = vector<int>(n+2);
        
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        for (int i = 0; i < m; i++) {
            int x, y;
            cin>>x>>y;
            unionSet(x, y);
        }
        
        memset(count, 0, sizeof(count));
        
        for (int i = 1; i <= n; i++) {
            root = findSet(i);
            count[root] += 1;
        }
        
        int max = 0;
        
        for (int i = 1; i <= n; i++) {
            if (count[i] > max) {
                max = count[i];
            }
        }
        
        printf("%d\n", max);
        parent.clear();
    }
}
