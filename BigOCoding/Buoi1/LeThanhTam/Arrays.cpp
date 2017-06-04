#include <vector>
#include <iostream>

using namespace std;

struct  aaa {
    bool count;
    int value;
};

int main() {
    
    
    vector<int> A;
    int nA, nB, k, m;
    cin>>nA;
    cin>>nB;
    cin>>k;
    cin>>m;
    
    for(int i = 0; i < nA; i++) {
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    
    int position = 0;
    bool result = true;
    bool exit = false;
    
    for(int i = 0; i < nB; i++) {
        int temp;
        cin>>temp;
        
        
        for(int j = position; j < k; j++) {
            if (A[j] < temp) {
                if (nB - i >= m) {
                    position++;
                }
                else {
                    exit = true;
                    break;
                }
            }
            else {
                break;
            }
        }
        
        if (exit == true) {
            break;
        }
    }
    
    if (position == k)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
