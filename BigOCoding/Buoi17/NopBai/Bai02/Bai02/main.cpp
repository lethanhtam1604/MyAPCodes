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

#define MAX 10005

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
    
    int n;
    scanf("%d", &n);
    
    int count[MAX];
    int root;
    
    int k = 1, u, v;
    string x, y;
    
    map<string, int> data;
    
    parent = vector<int>(n+2);
    
    vector<Pair> pairs;
    
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
    
    for (int i = 0; i < pairs.size(); i++) {
        unionSet(pairs[i].u, pairs[i].v);
    }
    
    for (int i = 1; i <= k - 1; i++) {
        root = findSet(i);
        count[root] += 1;
    }
    
    int max = 0;
    
    for (int i = 1; i <= k - 1; i++) {
        if (count[i] > max) {
            max = count[i];
        }
    }
    
    printf("%d\n", max);
    parent.clear();
    
}
