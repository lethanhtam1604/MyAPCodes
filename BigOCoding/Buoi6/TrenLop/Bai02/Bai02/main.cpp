//
//  main.cpp
//  Bai02
//
//  Created by Thanh-Tam Le on 4/4/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define MAX 10
int V, E;
bool visited[MAX];
list<int> graph[MAX];
int path[MAX];

void BFS(int s) {
    for(int i = 0; i < V; i++) {
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
        res += 1;
        if(f == s) {
            break;
        }
    }
    
    return res;
}

bool checkQueue(list<int> check, int node) {
    list<int>::iterator i;
    for(i = check.begin(); i != check.end(); i++) {
        if (*i == node) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    string s;
    cin>>s;
    
    for(int i = 0; i < s.length() - 1; i++) {
        if (s[i] - 48 != s[i + 1] - 48) {
            if (checkQueue(graph[s[i] - 48], s[i+1] - 48) == false) {
                graph[s[i] - 48].push_back(s[i+1] - 48);
            }
            
            if (checkQueue(graph[s[i + 1] - 48], s[i] - 48) == false) {
                graph[s[i + 1] - 48].push_back(s[i] - 48);
            }
        }
    }
    
    V = 0;
    for (int i = 0; i <= 9; i++) {
        if (graph[i].size() > 0) {
            V++;
        }
    }
    
    if (s.length() == 1) {
        cout<<1;
    }
    else {
        BFS(s[0] - 48);
        cout<<PrintResult(s[0] - 48, s[s.length() - 1] - 48, path);
    }
    
    return 0;
}
