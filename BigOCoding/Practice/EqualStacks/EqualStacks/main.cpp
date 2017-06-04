//
//  main.cpp
//  BalancedBrackets
//
//  Created by Thanh-Tam Le on 4/7/17.
//  Copyright © 2017 Tam. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    
    int sum1 = 0, sum2 = 0, sum3 = 0;
    
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
        cin >> h1[h1_i];
        sum1 += h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
        cin >> h2[h2_i];
        sum2 += h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
        cin >> h3[h3_i];
        sum3 += h3[h3_i];
    }
    
    int i = 0, j = 0, k = 0;
    
    while(1) {
        
        if (sum1 == sum2 && sum1 == sum3) {
            cout<<sum1;
            break;
        }
        else {
            if (i == n1 || j == n2 || k == n3) {
                cout<<0;
                break;
            }
            
            int minSum = min({sum1, sum2, sum3});
            
            if (sum1 > minSum) {
                sum1 -= h1[i];
                i++;
            }
            
            if (sum2 > minSum) {
                sum2 -= h2[j];
                j++;
            }
            
            if (sum3 > minSum) {
                sum3 -= h3[k];
                k++;
            }
        }
    }
    return 0;
}
