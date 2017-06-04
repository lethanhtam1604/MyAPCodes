#include <iostream>
#include <algorithm>

using namespace std;


struct seg {   
    int l, r, pos;
};

//x < y nghĩa là segment y cover segment x
bool operator <(const seg& x, const seg& y) {
    return x.l >= y.l && x.r <= y.r;
}

  
int main() {
    int n;
    cin >> n;
    
    seg big_seg, range;
    range.l = 0;
    range.r = 0;
    cin >> big_seg.l >> big_seg.r;
    big_seg.pos = 1;
	
    for (int i = 2; i <= n; ++i) {
    	// cout << "in loop";
        seg temp;
        cin >> temp.l >> temp.r;
        temp.pos = i;

        if (!(temp < big_seg)) { //nếu big segment ko cover temp
            if (big_seg < temp) {//nếu temp cover big segment thì update big segment
                big_seg = temp;
            } else { // temp va big segment ko cover lẫn nhau
                range.l = min({temp.l, temp.r, big_seg.l, big_seg.r});
                range.r = max({temp.l, temp.r, big_seg.l, big_seg.r});
            }
        }
    }

    if ((range.l == 0) || (range.l != 0 && range < big_seg)) {//range.l == 0 chỉ khi range vẫn nguyên sau khi khai báo
        cout << big_seg.pos;
    } else {
        cout << -1;
    }
	return 0;
}