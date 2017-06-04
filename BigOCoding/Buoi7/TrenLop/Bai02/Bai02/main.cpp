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
#define MAX 22
char maze[MAX][MAX];
bool visited[MAX][MAX];

bool BFS(Point src, Point des) {
    
    queue<Point> q;
    q.push(src);
    Point u;
    visited[src.x][src.y] = true;
    int x, y;
    
    while (!q.empty()) {
        u = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            x = u.x + dx[i];
            y = u.y + dy[i];
            
            if (x>= 0 && x <= m - 1 && y >= 0 && y <= n - 1) {
                
                if(maze[x][y] == '.' && visited[x][y] == false) {
                    visited[x][y] = true;
                    
                    if (x == des.x && y == des.y) {
                        return true;
                    }
                    
                    q.push(Point(x, y));
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
        
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin>>maze[i][j];
                if (maze[i][j] == '.' && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    points.push_back(Point(i, j));
                }
                visited[i][j] = false;
            }
        }
        
        if (points.size() == 2) {
            if (BFS(points[0], points[1]) == true) {
                cout<<"valid"<<endl;
            }
            else {
                cout<<"invalid"<<endl;
            }
        }
        else {
            cout<<"invalid"<<endl;
        }
    }
    
    return 0;
}
