//
//  main.cpp
//  Bai02
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
#define MAX 10010

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
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int s;
    cin>>s;
    vector<string> cities;
    
    dist = vector<int>(MAX, INF);
    graph = vector<vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());
    
    while (s--) {
        int n;
        cin>>n;

        for (int i = 1; i <= n; i++) {
            string name;
            cin>>name;
            cities.push_back(name);
            
            int p;
            cin>>p;
            
            for(int k = 0; k < p; k++) {
                int y, value;
                cin>>y>>value;
                graph[i].push_back(pair<int, int>(y, value));
            }
        }
        
        int r;
        cin>>r;
        
        for(int i = 0; i < r; i++) {
            string name1 = "", name2 = "";
            cin>>name1>>name2;
            
            int src = 1, des = 1;
            int sum = 0;
            
            for(int k = 0; k < cities.size(); k++) {
                if (cities[k] == name1) {
                    src = k + 1;
                    sum++;
                }
                
                if (cities[k] == name2) {
                    des = k + 1;
                    sum++;
                }
                
                if (sum == 2) {
                    break;
                }
            }
            
            Dijkstra(src, graph, dist);
            cout<<dist[des]<<endl;
            
            dist = vector<int>(MAX, INF);
            
        }
        
        cities.clear();
        for(int i = 1; i <= n; i++) {
            graph[i].clear();
        }
    }
    
    return 0;
}

//Bài toán này chỉ cần tạo ra được đồ thị (đồ thị có hướng) và áp dụng thuật toán dijkstra
//Thứ tự đỉnh của các thành phố lần lượt ra 1, 2, 3, 4...
//Duyệt qua từng thành phố tạo graph
//Từ 2 tền thành phố, tìm đỉnh của thành 2 thành phố đó.
//Chạy Dijkstra theo đỉnh nguồn và tìm chiều dài ngắn nhất theo đỉnh đích.




