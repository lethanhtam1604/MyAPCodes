#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <string.h>
#include <map>

using namespace std;
#define MAX 1010

const int INF = 1e9;
vector<pair<int, int> > graph[MAX];
vector<int> dist(MAX, INF);
bool visited[MAX];
int path[MAX];
int N;

int showResult() {
    int ans = 0;
    
    for(int i = 1; i <= N; i++) {
        if(path[i] == -1 && i == 1) {
            continue;
        }
        
        if(path[i] == -1 && i != 1) {
            return -1;
        }
        
        ans += dist[i];
    }
    
    return ans;
}

void prims(int src){
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(int i=0;i<graph[u].size();i++) {
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
    
    int T;
    cin >> T;
    
    for(int j = 1; j <= T; j++) {
        
        int M, w;
        cin >> M;
        string s1, s2;
        map<string, int> data;
        memset(path, -1, sizeof(path));

        int k = 1, u, v;
        for(int i = 0; i < M; i++){
            cin >> s1 >> s2 >> w;
            
            if(data.find(s1) == data.end()) {
                data[s1] = k++;
            }
            if(data.find(s2) == data.end()) {
                data[s2] = k++;
            }
            u = data[s1]; v = data[s2];
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        
        N = k - 1;
        
        prims(1);
        
        if (showResult() == -1) {
            printf("Case %d: Impossible\n", j);
        }
        else {
            printf("Case %d: %d\n", j, showResult());
        }
        
        dist = vector<int>(MAX, INF);
        for(int i = 1; i <= N; i++) {
            graph[i].clear();
            visited[i] = false;
        }
    }
    return 0;
}
