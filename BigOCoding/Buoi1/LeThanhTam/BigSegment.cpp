#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct coordinate {
    int a;
    int b;
    int index;
};

int main() {

    coordinate bigSegment, check;
    bool isCheck = false;
    int n;
    cin>>n;
    cin>>bigSegment.a;
    cin>>bigSegment.b;
    bigSegment.index = 1;


    for(int i = 2; i <= n; i++) {
        coordinate temp;
        cin>>temp.a;
        cin>>temp.b;
        temp.index = i;
        
        if (temp.a <= bigSegment.a && bigSegment.b <= temp.b) {
            bigSegment = temp;
        }
        else if (temp.a >= bigSegment.a && bigSegment.b >= temp.b) {
            continue;
        }
        else {
            check.a = min({bigSegment.a, temp.a});
            check.b = max({bigSegment.b, temp.b});
            isCheck = true;
        }
    }

    if (isCheck == false) {
        cout<<bigSegment.index;
    }
    else {
        if (check.a >= bigSegment.a && bigSegment.b >= check.b) {
            cout<<bigSegment.index;
        }
        else {
            cout<<-1;
        }
    }

    return 0;
}
