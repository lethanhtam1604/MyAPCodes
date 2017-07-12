#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <set>

using namespace std;

const int N = 105;
char A[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int n, m;
    cin>>n>>m;

    int res = 0;

    int height = 0, x1 = N, x2 = 0, y1 = N, y2 = 0;

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < m; ++j) {
            cin>>A[i][j];

            if (A[i][j] == 'B') {

                if (j < x1) {
                    x1 = j;
                }

                if (j > x2) {
                    x2 = j;
                }

                if (i < y1) {
                    y1 = i;
                }

                if (i > y2) {
                    y2 = i;
                }

            }
        }
    }

    bool flag = false;

    if (x1 == N) {
        cout<<"1";
    }
    else {
        height = x2 - x1 + 1;

        if (y2 - y1 + 1 > height) {
            height = y2 - y1 + 1;

            if (x2 - height + 1 >= 0) {
                x1 = x2 - height + 1;
                flag = true;
            }
            else if (x1 + height - 1 < m) {
                x2 = x1 + height - 1;
                flag = true;
            }
            else if (height <= m) {
                flag = true;
                x1 = 0;
                x2 = m - 1;
            }
        }
        else {

            if (y2 - height + 1 >= 0) {
                y1 = y2 - height + 1;
                flag = true;
            }
            else if (y1 + height - 1 < n) {
                y2 = y1 + height - 1;
                flag = true;
            }
            else if (height <= n) {
                flag = true;
                y1 = 0;
                y2 = n - 1;
            }
        }

        if (flag == true) {
            for (int i = y1; i <= y2; ++i) {
                for (int j = x1; j <= x2; ++j) {
                    if (A[i][j] == 'W') {
                        res++;
                    }
                }
            }
        }
        
        if (flag == false) {
            res = -1;
        }
        
        cout<<res;
        return 0;
    }
}
