#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> v;
    int n;
    cin>>n;

    int result = 0, maxP = 0, minP = 0;

    //find max and min position
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;

        if (temp == n) {
            maxP = i;
        }

        if (temp == 1) {
            minP = i;
        }
    }

    //calculate The distance between two elements in 2 cases
    if (minP > maxP) {
        if (n - minP - 1>= maxP) {
            cout<<n - maxP - 1;
        }
        else {
            cout<<minP;
        }
    }
    else {
        if (n - maxP - 1>= minP) {
            cout<<n - minP - 1;
        }
        else {
            cout<<maxP;
        }
    }

    return 0;
}
