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

using namespace std;

#define MAX 1000
int V, E;
bool visited[MAX];
list<int> graph[MAX];
int path[MAX];

void BFS(int s) {
    for(int i = 1; i <= V; i++) {
        visited[i] = false;
        path[i] = -1;
    }

    queue<int> q;
    visited[s] = true;
    q.push(s);
    list<int>::iterator i;

    while (!q.empty()) {
        s = q.front();
        q.pop();
        for(i = graph[s].begin(); i != graph[s].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
                path[*i] = s;
            }
        }
    }
}

int PrintResult(int s, int f, int back[]) {
    int res = 0;
    while (1) {
        f = back[f];
        res += 6;
        if(f == s) {
            break;
        }

        if (f == -1) {
            res = -1;
            break;
        }
    }

    return res;
}

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++) {
        int u, v;
        cin>>V>>E;
        for (int k = 1; k <= E; k++) {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        
        }

        int s;
        cin>>s;
        
        BFS(s);

        for (int k = 1; k <= V; k++) {
            if (k != s) {
                cout<<PrintResult(s, k, path)<<" ";
            }
        }
        
        for (int k = 1; k <= V; k++) {
            graph[k].clear();
        }
        cout<<endl;
    }

    return 0;
}
