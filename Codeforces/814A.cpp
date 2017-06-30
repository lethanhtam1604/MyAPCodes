
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int n, k, temp;
    vector<int> v;
    
    scanf("%d %d", &n, &k);
    
    if (k >= 2) {
        printf("Yes");
    }
    else {
        int min = -1, max = 201;
        
        bool flag = true;
        
        int begin = -1;
        
        for (int i = 0; i < n; i++) {
            
            scanf("%d", &temp);
            v.push_back(temp);
            
            if (temp == 0) {
                
                if (i != 0) {
                    min = v[i - 1];
                }
                
                if (i < n - 1) {
                    scanf("%d", &temp);
                    v.push_back(temp);
                    max = v[i + 1];
                    i++;
                }
            }
            else {
                if (v[i] > begin) {
                    begin = v[i];
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag == false) {
            printf("Yes");
        }
        else {
            int lost;
            scanf("%d", &lost);
            
            if (lost > min && lost < max) {
                printf("No");
            }
            else {
                printf("Yes");
            }
        }
    }
    
    return 0;
}
