#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    
    int n;
    scanf("%d", &n);
    vector<bool> v(50, false);
    
    for(int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        
        if (islower(c)) {
            c -= 32;
        }
        
        v[c-'A'] = true;
    }
    
    int dem = 0;
    for(int i = 0; i <= 26; i++) {
        if(v[i]==true) {
            dem++;
        }
    }
    if(dem == 26) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
