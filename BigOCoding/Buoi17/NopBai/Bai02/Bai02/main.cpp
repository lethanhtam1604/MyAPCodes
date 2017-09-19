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

#define MAX 1005

using namespace std;

struct Pair {
    int u;
    int v;
    
    Pair(int a, int b) {
        u = a;
        v = b;
    }
};

struct Request {
    string x;
    string y;

    Request(string a, string b) {
        x = a;
        y = b;
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
    
    int root;
    
    int k = 1, u, v;
    string x, y;
    
    map<string, int> data;

    vector<Pair> pairs;
    vector<Request> requests;

    for (int i = 1; i <= n; ++i) {
        
        cin>>x>>y;

        requests.push_back(Request(x, y));
        
        if(data.find(x) == data.end()) {
            data[x] = k++;
        }
        
        if(data.find(y) == data.end()) {
            data[y] = k++;
        }
        
        u = data[x]; v = data[y];

        pairs.push_back(Pair(u, v));
    }

    parent = vector<int>(k + 2);

    for (int i = 1; i <= k - 1; ++i) {
        parent[i] = i;
    }
    
    for (int i = 0; i < pairs.size(); ++i) {
        unionSet(pairs[i].u, pairs[i].v);
    }

    vector<string> result[k + 2];

    for (int i = 0; i < pairs.size(); ++i) {

        root = findSet(pairs[i].u);
        result[root].push_back(requests[i].x);
        result[root].push_back(requests[i].y);
    }

    vector<Request> res;

    for (int i = 1; i <= k - 1; ++i) {
        if (result[i].size() > 0) {
            res.push_back(Request(result[i][0], result[i][result[i].size() - 1]));
        }
    }

    cout<<res.size()<<endl;

    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i].x<<" "<<res[i].y<<endl;
    }

    return 0;
}
