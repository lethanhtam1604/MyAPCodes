#include <vector>
#include <iostream>

using namespace std;

int main() {

vector<int> A;
int n, m, count = 0, position = 0;
cin>>n;
cin>>m;


for(int i = 0; i < n; i++) {
    int temp;
    cin>>temp;
    A.push_back(temp);
}

for(int i = 0; i < m; i++) {
    int temp;
    cin>>temp;

	for(int j = position; j < n; j++) {
 		if (A[j] <= temp) {
 			count++;
 			position++;
 			break;
 		}
	}
}

cout<<n - count;

return 0;


}
