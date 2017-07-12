#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    long long n,k;
    scanf("%I64d %I64d", &n, &k);

    long long a = (n/2)/(k+1);
    long long b = k*a;
    long long c = n-(a+b);

    printf("%I64d %I64d %I64d\n", a, b, c);
}
