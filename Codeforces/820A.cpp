#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int c, v0, v1, a, l;
    scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);

    int res = 1, sum = v0, temp = v0;

    int t = 1;

    while (sum < c) {

        temp += v0 + t*a - l;

        if (v0 + t*a <= v1) {
            sum = temp;
        }
        else {
            sum += v1 - l;
        }

        res++;
        t++;
    }
    
    printf("%d", res);
    return 0;
}
