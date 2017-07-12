#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N=1005;

int a[N], b[N], c[N];

int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int A, B, res = 1;
    scanf("%d %d", &A, &B);

    int temp = min(A, B);

    for (int i = 2; i <= temp; i++) {
        res = res * i;
    }

    printf("%d", res);
    
    
    return 0;
}
