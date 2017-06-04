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
#define MAX 20000

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
    
    int N, n, m, s, t;
    cin>>N;
    dist = vector<int>(MAX, INF);
    graph = vector<vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());
    
    for(int k = 0; k < N; k++) {
        cin>>n>>m>>s>>t;
        
        for(int i = 0; i < m; i++) {
            int x, y, value;
            cin>>x>>y>>value;
            graph[x].push_back(pair<int, int>(y, value));
            graph[y].push_back(pair<int, int>(x, value));
        }
        
        if (m == 0) {
            cout<<"Case #"<<k + 1<<": unreachable"<<endl;
        }
        else {
            Dijkstra(s, graph, dist);
            if (dist[t] != INF) {
                cout<<"Case #"<<k + 1<<": "<<dist[t]<<endl;
            }
            else {
                cout<<"Case #"<<k + 1<<": unreachable"<<endl;
            }
        }
        
        dist = vector<int>(MAX, INF);
        for(int i = 0; i < n; i++) {
            graph[i].clear();
        }
    }
    
    return 0;
}

//Bài toàn này là đồ thì vô hướng
//Tạo graph từ bộ dữ liệu.
//Áp dụng thuật toán dijkstra và tìm đường đi ngắn nhất.




