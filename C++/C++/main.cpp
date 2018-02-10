#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
#include <limits>

using namespace std;

int main(){
    
#ifndef ONLINE_JUDGE
    freopen("/Users/thanhtamle/Documents/INPUT.txt", "rt", stdin);
#endif
    
    int n;
    cin>>n;
    
    vector<int> v;
    int temp;
    
    for(int i = 0; i < n; ++i) {
        cin>>temp;
        v.push_back(temp);
    }
    
    for(int i = 0; i < n; ++i) {

    }
    
    
    return 0;
}

//int main() {
//
//#ifndef ONLINE_JUDGE
//    freopen("/Users/thanhtamle/Documents/INPUT.txt", "rt", stdin);
//#endif
//
//    int n;
//    cin>>n;
//
//    if (n == 1) {
//        cout<<n<<endl;
//        return 0;
//    }
//
//    int temp;
//
//    vector<int> v;
//    vector<bool> b;
//    for(int i = 1; i <= n; ++i) {
//        cin>>temp;
//        v.push_back(i - temp);
//        b.push_back(false);
//    }
//
//    int j = 0;
//    int count = 0;
//    int pointer = -1;
//    for(int i = 1; i < n; ++i) {
//
//        while (j < i) {
//            if (b[j] == false && j + 1 >= v[i]) {
//                count++;
//                b[j] = true;
//            } else {
//                if (pointer == -1)
//                    pointer = j;
//            }
//
//            j++;
//        }
//
//        if (pointer != -1)
//            j = pointer;
//        pointer = -1;
//    }
//
//    cout<<n - count<<endl;
//
//    return 0;
//}


//int main() {
//
//#ifndef ONLINE_JUDGE
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
//#endif
//
//    bool A[N];
//    string s;
//    cin>>s;
//
//    for(int i = 0; i < s.length(); ++i) {
//        int index = s[i];
//        A[index] = true;
//    }
//
//    string b, temp;
//    cin>>b;
//
//    int n;
//    cin>>n;
//
//    int left = -1, right = -1;
//
//    for(int i = 0; i < n; ++i) {
//        cin>>temp;
//
//        for(int k = 0; k < temp.length(); ++k) {
//
//            if (k >= b.length()) {
//                cout<<"NO"<<endl;
//                break;
//            }
//            else {
//                if (b[k] != '*') {
//
//                    if (b[k] != '?') {
//                        if (b[k] != temp[k]) {
//                            cout<<"NO"<<endl;
//                            break;
//                        }
//                    }
//                    else {
//                        if (A[b[k]] == false) {
//                            cout<<"NO"<<endl;
//                            break;
//                        }
//                    }
//
//                }
//                else {
//                    left = k;
//                    right = k;
//                    break;
//                }
//            }
//        }
//
//        if (left == -1) {
//            cout<<"YES"<<endl;
//            break;
//        }
//        else {
//            int x = (int)b.length() - 1;
//            int y = (int)temp.length() - 1;
//            while (b[x] != '*' && y >= 0) {
//
//                if (b[x] != '?') {
//                    if (b[x] != temp[y]) {
//                        cout<<"NO"<<endl;
//                        break;
//                    }
//                }
//                else {
//                    if (A[b[x]] == false) {
//                        cout<<"NO"<<endl;
//                        break;
//                    }
//                }
//
//                x--;
//                y--;
//            }
//
//            right = x;
//
//            if (left)
//        }
//
//    }
//
//
//
//    return 0;
//}

//
//const int maxn = 1005;
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
