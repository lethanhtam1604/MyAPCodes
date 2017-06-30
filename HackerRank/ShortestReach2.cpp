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
#define MAX 3010

const int INF = 1e9;
vector<vector<int>> graph;
vector<int> dist(MAX, INF);
int path[MAX];
vector<vector<int>> lengthEdges;

void Dijkstra(int source, vector<vector<int>> &v, vector<int> &distance) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push(pair<int, int>(0, source));
    distance[source] = 0;
    
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int node = top.second;
        int d = top.first;
                
        for(int i = 0; i < v[node].size(); i++) {
            int neighbor = v[node][i];
            
            if (lengthEdges[node][neighbor] < distance[neighbor]) {
                distance[neighbor] = lengthEdges[node][neighbor];
                pq.push(pair<int, int>(distance[neighbor], neighbor));
                path[neighbor] = node;
            }
        }
    }
}

void PrintPath(int s, int f) {
    int b[MAX];
    int m = 0;
    while (1) {
        b[m++] = f;
        f = path[f];
        
        if(f == s) {
            b[m++] = s;
            break;
        }
        

    }
    
    for (int i = m - 1; i >= 0; i--) {
        cout<<b[i]<<" ";
    }
}


int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int t, n, m, s;
    cin>>t;
    dist = vector<int>(MAX, INF);
    graph = vector<vector<int>>(MAX + 5, vector<int>(MAX, -1));
    lengthEdges = vector<vector<int>>(MAX + 5, vector<int>(MAX, -1));
    
    while(t--) {
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
        
        cin>>s;
        
        Dijkstra(s, graph, dist);

        for(int i = 0; i < n; i++) {
            if (i == s) {
                cout<<0<<endl;
            }
            else {
                
                if (dist[i] != INF) {

                    cout<<dist[i]<<endl;
                }
                else {
                    cout<<"Impossible"<<endl;
                }
            }
        }
        
        PrintPath(1, 4);

        cout<<endl;
        
        
        dist.clear();
        dist = vector<int>(MAX, INF);
        for(int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        
        lengthEdges = vector<vector<int>>(MAX + 5, vector<int>(MAX, -1));
    }
    
    return 0;
}
