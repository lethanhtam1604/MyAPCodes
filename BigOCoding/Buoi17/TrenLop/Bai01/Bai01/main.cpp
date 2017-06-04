//
//  main.cpp
//  Bai01
//
//  Created by Thanh-Tam Le on 5/16/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <string>
#include <iostream>
#include <vector>
#include <sstream>  

using namespace std;

vector<int> parent;

int findSet(int u) {
    while(u != parent[u])
        u = parent[u];
    
    return u;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    parent[vp] = up;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    int t;
    cin>>t;
    
    int n;
    while (t--) {
        
        cin>>n;
        string s;
        cin.ignore();
        
        parent = vector<int>(n+1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        int success = 0, unsuccess = 0;

        while (getline(cin, s)) {
            
            if (s.size() == 0) {
                break;
            }
            
            stringstream ss(s);
            char a;
            int b, c;
            
            ss>>a>>b>>c;
            
            if (a == 'c') {
                unionSet(b, c);
            }
            else if (a == 'q') {
                int u = findSet(b);
                int v = findSet(c);
                
                if (u == v) {
                    success += 1;
                }
                else {
                    unsuccess += 1;
                }
            }
        }
        
        if (t != 0) {
            cout<<success<<","<<unsuccess<<endl<<endl;
        }
        else {
            cout<<success<<","<<unsuccess<<endl;
        }
    }
}
