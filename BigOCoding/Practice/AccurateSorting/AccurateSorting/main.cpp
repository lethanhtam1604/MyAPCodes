//
//  main.cpp
//  GukiZContest
//
//  Created by Thanh-Tam Le on 4/10/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;


int main() {
    
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int q;
    scanf("%d", &q);
    
    for (int i = 0 ; i < q; i++) {
        int n;
        scanf("%d", &n);
        
        if (n == 1 || n == 2) {
            cout<<"No"<<endl;
            break;
        }
        else {
            bool direct = false, flag = false;
            bool exist = false;
            int previousValue = 0;
            
            vector<int> v;
            for (int k = 0; k <  n; k++) {
                int temp;
                scanf("%d", &temp);
                v.push_back(temp);
            }
            
            for (int k = 0; k <  v.size(); k++) {
                if (flag == false && k >= 1 && previousValue != v[k]) {
                    if (previousValue < v[k]) {
                        direct = true;
                    }
                    else {
                        direct = false;
                    }
                    flag = true;
                }
                
                if (flag == true && previousValue != v[k]) {
                    
                    if (direct == true && previousValue > v[k]) {
                        exist = true;
                        cout<<"Yes"<<endl;
                        break;
                    }
                    
                    if (direct == false && previousValue < v[k]) {
                        exist = true;
                        cout<<"Yes"<<endl;
                        break;
                    }
                }
                
                previousValue = v[k];
                
            }
            
            if (!exist) {
                cout<<"No"<<endl;
            }
            
            v.clear();
        }
        
    }
}
