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

    int h, m;
    scanf("%d:%d", &h, &m);
    int ans = 0;

    while (1) {
        if (h/10 == m%10 || h%10 == m/10) {
            printf("%d\n", ans);
            return 0;
        }
        ++ans;
        ++m;
        h += m / 60;
        m %= 60;
        h %= 24;
    }
}
