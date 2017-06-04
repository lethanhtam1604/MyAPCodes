//
//  main.cpp
//  Bai01
//
//  Created by Thanh-Tam Le on 4/8/17.
//  Copyright © 2017 Tam. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define MAX 510

const int INF = 1e9;
vector<vector<int> > graph;
vector<int> dist(MAX, INF);
int path[MAX];
vector<vector<int> > lengthEdges;

void Dijkstra(int source, vector<vector<int> > &v, vector<int> &distance) {
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    pq.push(pair<int, int>(0, source));
    distance[source] = 0;
    
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int node = top.second;
        int d = top.first;
        
        for(int i = 0; i < v[node].size(); i++) {
            int neighbor = v[node][i];
            
            if (max(d, lengthEdges[node][neighbor]) < distance[neighbor]) {
                distance[neighbor] = max(d, lengthEdges[node][neighbor]);
                pq.push(pair<int, int>(distance[neighbor], neighbor));
                path[neighbor] = node;
            }
        }
    }
}

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int t, n, m, s;
    scanf("%d", &t);
    dist = vector<int>(MAX, INF);
    graph = vector<vector<int> >(MAX + 5, vector<int>(MAX, -1));
    lengthEdges = vector<vector<int> >(MAX + 5, vector<int>(MAX, -1));
    
    for(int k = 1; k <= t; k++) {
        cin>>n>>m;
        
        int a, b, c;
        for(int i = 0; i< m; i++){
            scanf("%d %d %d", &a, &b, &c);
            
            if(lengthEdges[a][b] == -1){
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
            
            if(lengthEdges[a][b] == -1 || lengthEdges[a][b] > c){
                lengthEdges[a][b] = c;
                lengthEdges[b][a] = c;
            }
        }
        
        scanf("%d", &s);

        Dijkstra(s, graph, dist);
        
        printf("Case %d:", k);
        
        for(int i = 0; i < n; i++) {
            if (i == s) {
                printf("\n0");
            }
            else {
                if (dist[i] != INF) {
                    printf("\n%d", dist[i]);
                }
                else {
                    printf("\nImpossible");
                }
            }
        }
        printf("\n");
        
        lengthEdges = vector<vector<int> >(MAX + 5, vector<int>(MAX, -1));
        dist = vector<int>(MAX, INF);
        for(int i = 0; i < n; i++) {
            graph[i].clear();
        }
    }
    return 0;
}
