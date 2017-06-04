//
//  main.cpp
//  BalancedBrackets
//
//  Created by Thanh-Tam Le on 4/7/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++) {
        string temp;
        cin>>temp;
        
        stack<char> s;
        int flag = true;
        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] == '{' || temp[j] == '[' || temp[j] == '(') {
                s.push(temp[j]);
            }
            else if (temp[j] == '}') {
                if (s.empty()) {
                    cout<<"NO"<<endl;
                    flag = false;
                    break;
                }
                else {
                    if (s.top() == '{') {
                        s.pop();
                    }
                    else {
                        cout<<"NO"<<endl;
                        flag = false;
                        break;
                    }
                }
            }
            else if (temp[j] == ']') {
                if (s.empty()) {
                    cout<<"NO"<<endl;
                    flag = false;
                    break;
                }
                else {
                    if (s.top() == '[') {
                        s.pop();
                    }
                    else {
                        cout<<"NO"<<endl;
                        flag = false;
                        break;
                    }
                }
            }
            else if (temp[j] == ')') {
                if (s.empty()) {
                    cout<<"NO"<<endl;
                    flag = false;
                    break;
                }
                else {
                    if (s.top() == '(') {
                        s.pop();
                    }
                    else {
                        cout<<"NO"<<endl;
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        if (flag == true) {
            if (s.empty()) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
    }
    
    return 0;
}
