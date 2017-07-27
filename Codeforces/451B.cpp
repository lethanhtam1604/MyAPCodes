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

const int N = 100010;
int A[N];
int B[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    ios :: sync_with_stdio(0);

    int n;
    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>A[i];
        B[i] = A[i];
    }

    sort(B, B + n);

    int start = 0, end = n - 1;

    bool startFlag = false, endFlag = false;

    while (start < end) {

        if (startFlag == true && endFlag == true) {
            break;
        }

        if (startFlag == false && start < end && A[start] == B[start]) {
            start++;
        }
        else {
            startFlag = true;
        }

        if (endFlag == false && start < end && A[end] == B[end]) {
            end--;
        }
        else {
            endFlag = true;
        }
    }

    if (start == end) {
        cout<<"yes"<<endl<<"1 1"<<endl;
    }
    else {
        int index = 0;
        for (int i = start; i <= end; ++i) {
            if (A[i] != B[end - index]) {
                cout<<"no"<<endl;
                return 0;
            }
            index++;
        }

        cout<<"yes"<<endl<<start + 1<<" "<<end + 1<<endl;
    }
    
    
    return 0;
}
