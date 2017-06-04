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

struct Student {
    
    int rating;
    int sum;
    int position;

    Student(int x = 0, int y = 0) {
        rating = x;
        sum = y;
    }
};

bool option(const Student &x, const Student &y) {
    return (int)x.rating > (int)y.rating;
}

int main() {
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    vector<int> v;
    vector<Student> s;
    
    int n;
    cin>>n;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
        
        bool flag = false;
        
        for(int k  = 0; k < s.size(); k++) {
            if (s[k].rating == temp) {
                flag = true;
                s[k].sum += 1;
                break;
            }
        }
        
        if(flag == false) {
            s.push_back(Student(temp, 1));
        }
    }
    
    sort(s.begin(), s.end(), option);
    
    int position = 0;
    
    for(int i = 0; i < s.size(); i++) {
        s[i].position = position + 1;
        position += s[i].sum;
    }
    
    for (int i = 0; i < n; i++) {
        
        for(int k  = 0; k < s.size(); k++) {
            if (s[k].rating == v[i]) {
                cout<<s[k].position<<" ";
            }
        }
        
    }
    
    return 0;
}
