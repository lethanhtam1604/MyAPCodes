//
//  main.cpp
//  Bai01
//
//  Created by Thanh-Tam Le on 4/8/17.
//  Copyright © 2017 Tam. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
#define MAX 510

const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];

void Dijkstra(int source, vector<vector<pair<int, int>>> &v, vector<int> &distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push(pair<int, int>(0, source));
    distance[source] = 0;
    
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int node = top.second;
        int d = top.first;
        
        for(int i = 0; i < v[node].size(); i++) {
            pair<int, int> neighbor = v[node][i];
            if (d + neighbor.second < distance[neighbor.first]) {
                distance[neighbor.first] = d + neighbor.second;
                pq.push(pair<int, int>(distance[neighbor.first], neighbor.first));
                path[neighbor.first] = node;
            }
        }
    }
}

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int n, s, t;
    dist = vector<int>(MAX, INF);
    cin>>n;
    graph = vector<vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());

    for(int i = 0; i < n; i++) {
        int x, y, value;
        cin>>x>>y>>value;
        graph[x].push_back(pair<int, int>(y, value));
        graph[y].push_back(pair<int, int>(x, value));
    }
    
    cin>>s;
    Dijkstra(s, graph, dist);
    
    cin>>t;
    
    for(int i = 0; i < t; i++) {
        int des;
        cin>>des;
        int res = dist[des];
        if (res != INF) {
            cout<<res<<endl;
        }
        else {
            cout<<"NO PATH"<<endl;
        }
    }
    
    return 0;
}
