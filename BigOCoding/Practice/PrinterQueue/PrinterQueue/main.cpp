//
//  main.cpp
//  PrinterQueue
//
//  Created by Thanh-Tam Le on 4/12/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <stdio.h>

using namespace std;

struct Printer {
    
    int jobNumber;
    bool jobPosition;
    
    Printer(int a = 0, bool b = false) {
        jobNumber = a;
        jobPosition = b;
    }
};

int main() {
    
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int t;
    scanf("%d", &t);
    

    
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        queue<Printer> q;
        vector<int> jobs;
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            
            int job;
            scanf("%d ", &job);
            
            if (i == m) {
                q.push(Printer(job, true));
            }
            else {
                q.push(Printer(job, false));
            }
            
            jobs.push_back(job);
        }
        
        sort(jobs.begin(), jobs.end(), greater<int>());
        
        int position = 0;
        
        while (!q.empty()) {
            Printer printer = q.front();
            q.pop();
            
            if (printer.jobNumber == jobs[position]) {
                res++;
                position++;
                
                if (printer.jobPosition == true) {
                    break;
                }
            }
            else {
                q.push(printer);
            }
        }
        
        printf("%d\n", res);
        jobs.clear();
    }
    
    
    return 0;
}
