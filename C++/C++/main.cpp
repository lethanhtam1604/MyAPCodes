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
#include <stack>
#include <queue>

using namespace std;

int const N = 100010;

int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    bool A[N];
    string s;
    cin>>s;

    for(int i = 0; i < s.length(); ++i) {
        int index = s[i];
        A[index] = true;
    }

    string b, temp;
    cin>>b;

    int n;
    cin>>n;

    int left = -1, right = -1;

    for(int i = 0; i < n; ++i) {
        cin>>temp;

        for(int k = 0; k < temp.length(); ++k) {

            if (k >= b.length()) {
                cout<<"NO"<<endl;
                break;
            }
            else {
                if (b[k] != '*') {

                    if (b[k] != '?') {
                        if (b[k] != temp[k]) {
                            cout<<"NO"<<endl;
                            break;
                        }
                    }
                    else {
                        if (A[b[k]] == false) {
                            cout<<"NO"<<endl;
                            break;
                        }
                    }

                }
                else {
                    left = k;
                    right = k;
                    break;
                }
            }
        }

        if (left == -1) {
            cout<<"YES"<<endl;
            break;
        }
        else {
            int x = (int)b.length() - 1;
            int y = (int)temp.length() - 1;
            while (b[x] != '*' && y >= 0) {

                if (b[x] != '?') {
                    if (b[x] != temp[y]) {
                        cout<<"NO"<<endl;
                        break;
                    }
                }
                else {
                    if (A[b[x]] == false) {
                        cout<<"NO"<<endl;
                        break;
                    }
                }

                x--;
                y--;
            }

            right = x;

            if (left)
        }

    }



    return 0;
}


//const int maxn = fds;
//long long f[maxn];
//const int mod = 1e9 + 7;
//int isPrime[maxn];
//
//int main() {
//#ifndef ONLINE_JUDGE
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
//#endif
//
//    for(int i = 2; i < maxn; ++i) {
//        isPrime[i] = i;
//    }
//
//    for (int i = 2; i * i < maxn; ++i) {
//        if (isPrime[i] == i)
//            for (int j = i * i; j < maxn; j += i)
//                isPrime[j] = min(i, isPrime[j]);
//    }
//
//    f[1] = 0;
//    for (int i = 2; i < maxn; ++i) {
//        f[i] = 1LL * i * (i-1)/2;
//        f[i] = 1LL*f[isPrime[i]] * (i/isPrime[i]) + 1LL*f[i/isPrime[i]];
//    }
//
//
//    int t, l, r;
//    cin >> t >> l >> r;
//    long long ans = 0;
//    long long pro = 1;
//    for(int i = l; i <= r; i++) {
//        f[i] %= mod;
//        ans = 1LL * ans + 1LL * pro * f[i];
//        pro *= 1LL * t;
//        pro %= mod;
//        ans %= mod;
//    }
//    cout << ans << endl;
//    return 0;
//}

//int main() {
//#ifndef ONLINE_JUDGE
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
//#endif
//
//    unordered_set<int> comp;
//
//    int n, sum, temp;
//    scanf("%d %d", &n, &sum);
//
//    for(int i = 0; i < n; ++i) {
//        scanf("%d", &temp);
//        if (comp.find(temp) != comp.end()) {
//            printf("Yes");
//            return 0;
//        }
//        comp.insert(sum-temp);
//    }
//
//    printf("No");
//    return 0;
//}
