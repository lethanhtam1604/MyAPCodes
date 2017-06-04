//
//  main.cpp
//  Bai01
//
//  Created by Thanh-Tam Le on 4/4/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;
    Point(int a=0, int b=0){
        x = a;
        y = b;
    }
};

int t, m, n;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
#define MAX 102
char maze[MAX][MAX];
bool visited[MAX][MAX];

string A, L, I, Z, W, E;

void allizzwell(int x, int y) {
    if (maze[x][y] == 'A') {
        A += 'A';
    }
    
    if (maze[x][y] == 'L') {
        L += 'L';
    }
    
    if (maze[x][y] == 'I') {
        I += 'I';
        
    }
    
    if (maze[x][y] == 'Z') {
        Z += 'Z';
        
    }
    
    if (maze[x][y] == 'W') {
        W += 'W';
        
    }
    
    if (maze[x][y] == 'E') {
        E += 'E';
    }
}

bool DFS(Point src) {
    
    allizzwell(src.x, src.y);
    
    stack<Point> s;
    s.push(src);
    Point u;
    visited[src.x][src.y] = true;
    int x, y;
    
    while (!s.empty()) {
        u = s.top();
        s.pop();
        
        for(int i = 0; i < 4; i++) {
            x = u.x + dx[i];
            y = u.y + dy[i];
            
            if (x>= 0 && x <= m - 1 && y >= 0 && y <= n - 1) {
                
                if(visited[x][y] == false) {
                    visited[x][y] = true;
                    allizzwell(x, y);
                    s.push(Point(x, y));

                    if (A.size() >= 1 && L.size() >= 4 && I.size() >= 1 && Z.size()>= 2 && W.size() >= 1 && E.size()>= 1) {
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    cin>>t;
    vector<Point> points;
    
    for(int k = 0; k < t; k++) {
        cin>>m>>n;
        points.clear();
        A = "", L = "", I = "", Z = "", W = "", E = "";
        
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin>>maze[i][j];
                visited[i][j] = false;
                if (maze[i][j] == 'A') {
                    points.push_back(Point(i,j));
                }
            }
        }
        
        bool flag = false;
        
        for(int i = 0; i < points.size(); i++) {
                if (DFS(points[i]) == true) {
                    flag = true;
                    break;
                }
        }
        
        if (flag == true) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
