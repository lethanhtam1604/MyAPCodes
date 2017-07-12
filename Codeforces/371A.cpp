#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N=105;

int a[N], b[2];

int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int n, k;
    scanf("%d %d", &n, &k);
    int res = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int t = 0; t < k; t++) {
        for(int i = t; i < n; i+= k) {
            if (a[i] == 1) {
                b[0]++;
            }
            else {
                b[1]++;
            }
        }

        res += min(b[0], b[1]);
        b[0] = 0;
        b[1] = 0;
    }

    printf("%d", res);
    
    
    return 0;
}
