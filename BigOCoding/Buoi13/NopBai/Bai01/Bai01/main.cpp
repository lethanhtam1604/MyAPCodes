//
//  main.cpp
//  Bai01
//
//  Created by Thanh-Tam Le on 4/22/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <stdio.h>
#include <set>
#include <sstream>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif
    
    int t;
    scanf("%d", &t);
    
    set<string> s;
    
    string content;
    string word;
    string temp;
    
    while (getline(cin, content)) {
        
        if (content.size() == 0) {
            continue;
        }
        
        stringstream ss(content);
        
        while (ss>>word) {
            
            temp = "";
            
            for (int i = 0; i < word.length(); i++) {
                
                if (isalpha(word[i]) != 0) {
                    if (isupper(word[i]) == 1) {
                        temp += word[i] + 32;
                    }
                    else {
                        temp += word[i];
                    }
                }
            }
            
            if (temp.length() > 0) {
                s.insert(temp);
            }
        }
    }
    
    set<string>::iterator it;
    
    for(it = s.begin(); it != s.end(); it++) {
        printf("%s\n", (*it).c_str());
    }
    
    s.clear();
    
    return 0;
}
