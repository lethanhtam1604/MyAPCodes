#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> v;
    int n, h;
    cin>>n;
    cin>>h;

    int result = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        if (temp <= h) {
            result++;
        }
        else {
            result = result + 2;
        }
    }
    cout<<result;
    return 0;
}
