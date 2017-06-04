//
//  main.cpp
//  Bai01
//
//  Created by Thanh-Tam Le on 4/4/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

#define MAX 100000
int V, E;
bool visited[MAX];
list<int> graph[MAX];
int path[MAX];

void DFS(int src) {
    
    stack<int> s;
    visited[src] = true;
    s.push(src);
    list<int>::iterator i;
    
    while (!s.empty()) {
        src = s.top();
        s.pop();
        for(i = graph[src].begin(); i != graph[src].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                s.push(*i);
                path[*i] = src;
            }
        }
    }
}

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++) {
        int u, v;
        cin>>V>>E;
        for (int k = 0; k < E; k++) {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int res = 0;
        
        for(int i = 0; i < V; i++) {
            visited[i] = false;
            path[i] = -1;
        }
        
        for(int i = 0; i < V; i++) {
            if (visited[i] == false) {
                DFS(i);
                res++;
            }
        }
        
        cout<<res<<endl;
        
        for (int k = 0; k < V; k++) {
            graph[k].clear();
        }
    }
    
    return 0;
}
