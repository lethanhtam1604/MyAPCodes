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

int begin = 0;

for(int i = 0; i < n; i++) {
    if (begin + 15 < v[i]) {
        break;
    }
    begin = v[i];
}
if (begin == 90 || (begin + 15) >= 90)
    cout<<90;
else
    cout<<begin + 15;
return 0;
}
