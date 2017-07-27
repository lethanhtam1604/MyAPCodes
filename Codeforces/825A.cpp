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


int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int n, res = 0;
    cin>>n;

    char temp;

    string s;

    for(int i = 0; i < n; ++i) {
        cin>>temp;

        if (temp == '0') {
            cout<<res;
            res = 0;
        }

        res += temp - '0';
    }

    cout<<res<<endl;
    
    return 0;
}
