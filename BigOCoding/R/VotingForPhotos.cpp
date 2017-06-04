#include <vector>
#include <iostream>

using namespace std;

int main() {

vector<int> A;
int n;
cin>>n;

for(int i = 0; i < n; i++) {
    int temp;
    cin>>temp;
    A.push_back(temp);
}

return 0;
}
