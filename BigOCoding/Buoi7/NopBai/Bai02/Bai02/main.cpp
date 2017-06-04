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
#include <stack>

using namespace std;

struct Point {
    int x;
    int y;
    int value;
    
    Point(int a=-1, int b=-1) {
        x = a;
        y = b;
    }
};


#define MAX 50010
int V, E;
bool visited[MAX];
list<Point> graph[MAX];
Point path[MAX];
int length[MAX];

void DFS(int src) {
    for(int k = 1; k <= V; k++) {
        visited[k] = false;
        path[k] = Point();
        length[k] = 0;
    }
    
    stack<int> s;
    visited[src] = true;
    s.push(src);
    list<Point>::iterator i;
    
    while (!s.empty()) {
        src = s.top();
        s.pop();
        for(i = graph[src].begin(); i != graph[src].end(); i++) {
            if (!visited[(*i).y]) {
                visited[(*i).y] = true;
                s.push((*i).y);
                Point point = Point(-1, src);
                point.value = (*i).value;
                path[(*i).y] = point;
                length[(*i).y] = point.value + length[src];
            }
        }
    }
}

int findVertexMax() {
    int max = length[1], res = 1;
    for(int i = 2; i <= V; i++) {
        if (length[i] > max) {
            max = length[i];
            res = i;
        }
    }

    return res;
}

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++) {
        cin>>V;
        for (int k = 0; k < V - 1; k++) {
            int u, v, value;
            cin>>u>>v>>value;
            Point point1, point2;
            point1.y = v;
            point1.value = value;
            point2.y = u;
            point2.value = value;
            graph[u].push_back(point1);
            graph[v].push_back(point2);
        }
        
        DFS(1);
        
        int indexMax = findVertexMax();
        
        DFS(indexMax);

        cout<<length[findVertexMax()]<<endl;

        for (int k = 1; k <= V; k++) {
            graph[k].clear();
        }
    }
    
    return 0;
}



//Bài này thì để tìm ra đường đi dài nhất trong khi chưa biết điểm đầu vào và điểm đích.
//Đầu tiền ta sử dụng thuật toán DFS chạy từ 1 đỉnh bất kỳ.
//Khởi tạo mảng length[MAX] chứa chiều dài của tất cả các đỉnh.
//Ở lần đầu tiền duyệt DFS, ta tính toán chiều dài của tất cả các đỉnh. Sau đó tìm ra đỉnh có chiều dài lớn nhất.
//Tiếp theo duyệt DFS lần 2 từ đỉnh có chiều dài lớn nhất. Sau đó lấy ra đỉnh có chiều dài lớn nhất lần nữa. Và đó là kết quả cuối cùng của bài toán.




