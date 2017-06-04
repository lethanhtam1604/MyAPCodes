
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>
#include <stdio.h>
#include <set>

using namespace std;
#define MAX 1010

const int INF = 1e9;
vector<pair<int, int> > graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N;

void showResult(int priceOneFurlong ) {
    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        if(path[i] == -1) {
            continue;
        }
        ans += dist[i] * priceOneFurlong;
    }
    
    cout<<ans<<endl;
}

void prims(int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(int i = 0; i<graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(w, v));
                path[v] = u;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    int t, p, m, u, v, w;
    cin>>t;
    
    while(t--) {
        cin >> p >> N >> m;
        memset(path, -1, sizeof(path));
        for(int i = 0; i< m; i++){
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        
        prims(1);
        
        showResult(p);
        
        dist = vector<int>(MAX, INF);
        for(int i = 1; i <= N; i++) {
            graph[i].clear();
            visited[i] = false;
        }
    }
    
    return 0;
}
