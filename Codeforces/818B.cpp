#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX = 105;

int l[MAX], ans[MAX], test[MAX];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0;i<m;++i) {
        scanf("%d", &l[i]);
    }

    memset(ans, -1, sizeof(ans));
    memset(test, -1, sizeof(test));

    for(int i=0;i<m-1;++i) {
        int k = l[i] < l[i+1] ? l[i+1] - l[i] : n - l[i] + l[i+1];
        if (ans[l[i]] == -1) {
            ans[l[i]] = k;
            continue;
        }

        if (ans[l[i]] != k) {
            printf("-1");
            return 0;
        }

    }

    for(int i=1;i<=n;++i) {
        test[ans[i]]++;

        if (ans[i] != -1 && test[ans[i]] > 0) {
            printf("-1");
            return 0;
        }
    }

    for(int i=1;i<=n;++i) {
        if(ans[i] == -1) {
            for(int j = 1; j<= n; j++) {
                if (test[j] == -1) {
                    ans[i] = j;
                    test[j] = 0;
                    break;
                }
            }
        }
    }

    for(int i=1;i<=n;++i) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}
