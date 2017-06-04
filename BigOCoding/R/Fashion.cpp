
#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> v;
    int n;
    cin>>n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    if (n == 1 && v[0] == 1) {
        cout<<"YES";
    }
    else if (n == 1 && v[0] == 0) {
        cout<<"NO";
    }
    else {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                count++;
            }

            if (count > 1) {
                break;
            }
        }
        if (count > 1) {
            cout<<"NO";
        }
        else {
            cout<<"YES";
        }
    }
    return 0;
}
