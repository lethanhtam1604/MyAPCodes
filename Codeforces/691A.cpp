#include <vector>
#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;

    if (n == 1) {
        int temp;
        cin>>temp;
        if (temp == 1) {
            cout<<"YES";
        }
        else {
            cout<<"NO";
        }
    }
    else {
        int count = 0;

        for (int i = 0; i < n; i++) {
            int temp;
            cin>>temp;

            if (temp == 0) {
                count++;
            }

            if (count > 1) {
                break;
            }
        }

        if (count == 1) {
            cout<<"YES";
        }
        else {
            cout<<"NO";
        }
    }
    return 0;
}
