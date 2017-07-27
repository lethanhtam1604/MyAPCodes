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


int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    string a, b, c;
    cin>>a>>b>>c;


    unordered_map<char, char> u;

    for (int i = 0; i < a.length(); ++i) {
        u[a[i]] = b[i];
    }

    for (int i = 0; i < c.length(); ++i) {

        unordered_map<char, char>::iterator got = u.find(tolower(c[i]));

        if (got != u.end()) {
            if (c[i] >= 'a' && c[i] <= 'z') {
                printf("%c", (*got).second);
            }
            else {
                printf("%c", toupper((*got).second));
            }
        }
        else {
            printf("%c", c[i]);
        }
    }
    
    return 0;
}
