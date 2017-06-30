
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    int n, a;
    scanf("%d %d", &n, &a);

    if (n == 3) {
        printf("1 2 3");
        return 0;
    }

    double angle = (1 - 2 * 1.0/n) * 180;

    int cheo = n - 3;
    int sogoc = 2 + cheo - 1;
    double angleSmallest = (angle*1.0)/sogoc;

    double angleChoose = abs(angle - a);

    int index = 0;

    for (int i = 1; i < sogoc; i++) {
        if (angleChoose > abs(angle - (angleSmallest*i) - a)) {
            angleChoose = abs(angle - (angleSmallest*i) - a);
            index = i;
        }
    }

    printf("1 2 %d", 2 + index + 1);
    
    return 0;
}
