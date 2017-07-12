#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N=55;

int a[N][N];

int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int n;
    scanf("%d", &n);
    int sum = 0, flag = false;

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {

            if (a[i][j] != 1) {

                for (int k = 0; k < n; k++) {

                    if (k != j) {

                        for (int t = 0; t < n; t++) {

                            sum = 0;

                            if(t != i) {
                                sum += a[i][k] + a[t][j];

                                if (sum == a[i][j]) {
                                    flag = true;
                                    break;
                                }
                            }
                        }

                        if (flag == true) {
                            break;
                        }
                    }

                }
                
                if (flag == false) {
                    printf("No");
                    return 0;
                }
                
                flag = false;
            }
        }
    }
    
    printf("Yes");
    return 0;
}
