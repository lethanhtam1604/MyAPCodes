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

const int N = 1000010;
int A[N];
string s[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    ios :: sync_with_stdio(0);

    int n, k, x;
    cin>>n;

    int max = 0;

    string temp;

    for(int r = 1; r <= n; ++r) {
        cin>>temp>>k;

        for(int i = 0; i < k; ++i) {
            cin>>x;

            if (x > max) {
                max = x;
            }

            if (temp.length() > s[A[x]].length()) {
                A[x] = r;
            }
        }

        s[r] = temp;
    }

    string res = "";

    for(int i = 1; i < N; ++i) {

        if (i > max) {
            break;
        }

        if (s[A[i]].length() != 0) {
            for (int t = (int)res.length() - i + 1; t < s[A[i]].length(); ++t) {
                res += s[A[i]][t];
            }
        }
        else {
            if (i > res.length()) {
                res += 'a';
            }
        }
    }
    
    cout<<res<<"\n";
    
    return 0;
}
