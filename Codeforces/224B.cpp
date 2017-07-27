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

const int N = 100010;
int A[N];
int B[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    ios :: sync_with_stdio(0);

    set<int> s;

    int n, k;
    cin>>n>>k;

    for (int i = 1; i <= n; ++i) {
        cin>>A[i];
        s.insert(A[i]);
        B[A[i]]++;

        if (s.size() == k) {

            for (int k = 1; k <= i; ++k) {

                if (B[A[k]] > 1) {
                    B[A[k]]--;
                }
                else {
                    cout<<k<<" "<<i;
                    return 0;
                }
            }

        }
    }
    
    cout<<"-1 -1";
    
    return 0;
}
