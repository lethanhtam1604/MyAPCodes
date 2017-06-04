//
//  main.cpp
//  BeautifulWord
//
//  Created by Thanh-Tam Le on 4/10/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);

    string w;
    cin>>w;
    
    stack<char> s;
    
    bool flag = false;
    
    for (int i = 0; i < w.length(); i++) {
        if (s.empty()) {
            s.push(w[i]);
        }
        else {
            char c = s.top();
            if (c == w[i]) {
                flag = true;
                cout<<"No"<<endl;
                break;
            }
            else if ((w[i] == 'a' || w[i] == 'e' || w[i] == 'i' || w[i] == 'o' || w[i] == 'u' || w[i] == 'y') && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')) {
                flag = true;
                cout<<"No"<<endl;
                break;
            }
            else {
                s.pop();
                s.push(w[i]);
            }
        }
    }
    
    if (flag == false) {
        cout<<"Yes"<<endl;
    }
    
    return 0;
}
