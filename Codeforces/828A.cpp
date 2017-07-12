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

    int n, a, b;
    int res = 0, oneSeat = 0, twoSeat = 0, onetwoSeat = 0;

    cin>>n>>a>>b;

    oneSeat = a;
    twoSeat = b;


    for(int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;

        if (temp == 1) {

            if (oneSeat > 0) {
                oneSeat--;
                continue;
            }

            if (twoSeat > 0) {
                onetwoSeat++;
                twoSeat--;
            }
            else if (onetwoSeat > 0) {
                onetwoSeat--;
            }
            else{
                res++;
            }

        }
        else {
            if (twoSeat > 0) {
                twoSeat--;
            }
            else {
                res+=2;
            }
            
        }
    }
    cout<<res;
    return 0;
}
