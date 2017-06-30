#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N=200007;

int a[N];
int b[N];

int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int n, k, temp;
    scanf("%d %d", &n, &k);

    int periodic = n/k;

    vector<int> v, l;

    int t = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        v.push_back(temp);

        sum+= temp;
        t++;
        if (t == periodic) {
            t = 0;
            l.push_back(sum);
            sum = 0;
        }
    }

    for (int i = 0; i < l.size(); i++) {

    }
}
