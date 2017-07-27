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

    int n;
    cin>>n;

    if (n==1 || n==2) {
        printf("YES");
        return 0;
    }

    int A[105];
    int constant = 0, decreasing = 0;

    for(int i = 0; i < n; ++i) {
        cin>>A[i];

        if (i>0) {
            if(A[i] == A[i-1]) {
                constant++;
            }

            if(A[i] < A[i-1]) {
                decreasing++;
            }

            if (constant != 0) {
                if (A[i] > A[i-1]) {
                    printf("NO");
                    return 0;
                }
            }

            if (decreasing != 0) {
                if (A[i] >= A[i-1]) {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    
    printf("YES");
    
    return 0;
}
