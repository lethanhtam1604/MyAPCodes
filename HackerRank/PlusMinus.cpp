#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    
    int positiveN = 0, negativeN = 0, zeroN = 0;
    int temp;
    
    for(int arr_i = 0; arr_i < n; arr_i++){
        scanf("%d", &temp);
        
        if (temp == 0) {
            zeroN++;
        }
        else if (temp < 0) {
            negativeN++;
        }
        else {
            positiveN++;
        }
    }
    
    printf("%.6f\n", (1.0*positiveN)/n);
    printf("%.6f\n", (1.0*negativeN)/n);
    printf("%.6f\n", (1.0*zeroN)/n);
    
    return 0;
}
