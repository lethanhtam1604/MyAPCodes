//
//  main.cpp
//  BigOCoding
//
//  Created by Thanh-Tam Le on 3/18/17.
//  Copyright © 2017 BigOCoding. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <string>
#include <list>
#include <queue>
#include <stack>

using namespace std;

//int main() {
//
//    string s, t, result;
//    getline(cin, s);
//    getline(cin, t);
//    
//    int position = 0;
//    
//    bool exist = false;
//    
//    for (int i = 0; i < s.length(); i++) {
//        result += s[i];
//        if (s[i] < t[i]) {
//            exist = true;
//            position = i;
//            break;
//        }
//    }
//    
//    if (!exist) {
//        cout<<"No such string";
//    }
//    else {
//        if (position == s.length() - 1) {
//            if (s[position] + 1 < t[position]) {
//                s[position] = s[position] + 1;
//                cout<<s;
//            }
//            else {
//                cout<<"No such string";
//            }
//        }
//        else {
//            
//        }
//        for (int i = 0; i < result.length(); i++) {
//            
//            if (result[i] > t[i]) {
//                exist = false;
//                break;
//            }
//        }
//        
//        if (!exist) {
//            cout<<"No such string";
//        }
//        else {
//            cout<<result;
//        }
//    }
//
//    return 0;
//}


//int main() {
//    
//    string s;
//    cin>>s;
//    int result = 0;
//    
//    char currentC = 'a';
//    
//    for (int i = 0; i < s.length(); i++) {
//        
//        int alpha = abs(currentC - s[i]);
//        
//        if (alpha <= 13) {
//            result += alpha;
//        }
//        else {
//            result = result + 26 - alpha;
//        }
//        currentC = s[i];
//    }
//    
//    cout<<result;
//    return 0;
//}''

//int main() {
//
//    freopen("/Users/d/Documents/INPUT.TXT", "rt", stdin);
//
//    vector<int> A;
//    int n, m, count = 0, position = 0;
//    cin>>n;
//    cin>>m;
//
//
//    for(int i = 0; i < n; i++) {
//        int temp;
//        cin>>temp;
//        A.push_back(temp);
//    }
//
//    for(int i = 0; i < m; i++) {
//        int temp;
//        cin>>temp;
//
//        for(int j = position; j < n; j++) {
//            if (A[j] <= temp) {
//                count++;
//                position++;
//                break;
//            }
//        }
//    }
//    cout<<n - count;
//    return 0;
//}

//using namespace std;
//
//struct Friend {
//    int x;
//    int y;
//    int count = 0;
//};
//
//bool option(const Friend &x, const Friend &y) {
//    return (int)x.count > (int)y.count;
//}
//
//int maxTokens(int friends_nodes, vector < int > friends_from, vector < int > friends_to, vector < int > friends_weight) {
//    
//    vector<Friend> result;
//    for (int i = 0; i < friends_from.size(); i++) {
//        bool flag = false;
//        
//        for (int k = 0; k < result.size(); k++) {
//            if (friends_from[i] == result[k].x && friends_to[i] == result[k].y) {
//                result[k].count += 1;
//                flag = true;
//                break;
//            }
//        }
//        
//        if (flag == false) {
//            Friend temp;
//            temp.x = friends_from[i];
//            temp.y = friends_to[i];
//            temp.count = 1;
//            result.push_back(temp);
//        }
//    }
//    
//    sort(result.begin(), result.end(), option);
//    int tokens = result[0].count;
//    int res = 0, max = result[0].x * result[0].y;
//    
//    for (int i = 1; i < result.size(); i++) {
//        if (result[i].count == tokens) {
//            res = result[i].x * result[i].y;
//            if (res > max) {
//                max = res;
//            }
//        }
//        else {
//            break;
//        }
//    }
//    
//    return max;
//}
//
//int main(){
////    freopen("/Users/d/Documents/INPUT.TXT", "rt", stdin);
//    int res;
//    
//    int _friends_nodes = 0;
//    int _friends_edges = 0;
//    
//    cin >> _friends_nodes >> _friends_edges;
//    
//    vector<int> _friends_from(_friends_edges);
//    vector<int> _friends_to(_friends_edges);
//    vector<int> _friends_weight(_friends_edges);
//    
//    for (int _friends_i = 0; _friends_i < _friends_edges; _friends_i++) {
//        cin >> _friends_from[_friends_i] >> _friends_to[_friends_i] >> _friends_weight[_friends_i];
//    }
//    
//    res = maxTokens(_friends_nodes, _friends_from, _friends_to, _friends_weight);
//    cout << res << endl;
//    
//    //cout.close();
//    return 0;
//}

//string convertToAlphabet(string s) {
//    string result = "";
//    for (int k = 0; k < s.length(); k++) {
//        if (s[k] != '-' && s[k] != ';' && s[k] != '_') {
//            result += tolower(s[k]);
//        }
//    }
//    return result;
//}
//
//int main() {
//    
//    string a, b, c;
//    cin>>a;
//    cin>>b;
//    cin>>c;
//    
//    vector<string> v;
//    string temp1 = convertToAlphabet(a);
//    string temp2 = convertToAlphabet(b);
//    string temp3 = convertToAlphabet(c);
//    
//    v.push_back(temp1 + temp2 + temp3);
//    v.push_back(temp1 + temp3 + temp2);
//    v.push_back(temp2 + temp3 + temp1);
//    v.push_back(temp2 + temp1 + temp3);
//    v.push_back(temp3 + temp2 + temp1);
//    v.push_back(temp3 + temp1 + temp2);
//
//    int n;
//    cin>>n;
//    
//    for (int i = 0; i < n; i++) {
//        string temp;
//        cin>>temp;
//        string result = convertToAlphabet(temp);
//        
//        bool flag = false;
//        for (int i = 0; i < v.size(); i++) {
//            if (v[i].compare(result) == 0) {
//                flag = true;
//                break;
//            }
//        
//        }
//        
//        if (flag) {
//            cout<<"ACC"<<endl;
//        }
//        else {
//            cout<<"WA"<<endl;
//        }
//    }
//    return 0;
//}

//int main() {
//
//    //freopen("/Users/TamLe/BigOCoding/BigOCoding/Input.txt", "rt", stdin);
//
//    vector<int> A;
//    int n, t, sum = 0, count = 0, j = 0, result = 0;
//    cin>>n;
//    cin>>t;
//
//    for(int i = 0; i < n; i++) {
//        int temp;
//        cin>>temp;
//        A.push_back(temp);
//        sum = sum + temp;
//
//        if (sum <= t) {
//            count++;
//        }
//        else {
//            result = max({count, result});
//            sum = sum - A[j];
//            j++;
//        }
//    }
//    result = max({count, result});
//    cout<<result;
//    return 0;
//}


//int main() {
//    
//    vector<int> v, a;
//    int n, k, count = 1, j = 1, length = 10^5 + 1, l = -1, r = -1;
//    bool read = true, check = true;
//    cin>>n;
//    cin>>k;
//    
//    int first;
//    cin>>first;
//    a.push_back(first);
//    
//    for(int i = 2; i <= n; i++) {
//        int temp;
//        cin>>temp;
//        v.push_back(temp);
//        
//        bool distinct = true;
//        for(int t = j; t < a.size(); t++) {
//            if (temp == a[t]) {
//                distinct = false;
//                break;
//            }
//        }
//        
//        if (distinct == true) {
//            a.push_back(temp);
//        }
//        
//        if (check && temp == v[i-1]) {
//            j++;
//            continue;
//        }
//        else {
//            check = false;
//        }
//        
//        if (a.size() >= k) {
//            if (length > i - j + 1) {
//                length = i - j + 1;
//                l = j;
//                r = i;
//            }
//            
//            if (i -j + 1 == k) {
//                break;
//            }
//            
//            j++;
//            check = true;
//        }
//    }
//    
//    if (a.size() == k) {
//        cout<<l;
//        cout<< " ";
//        cout<<r;
//    }
//    else {
//        cout<<"-1 -1";
//    }
//    
//    return 0;
//}

//struct Pair {
//    int u;
//    int v;
//};
//
//int main() {
//
//    //freopen("/Users/TamLe/BigOCoding/BigOCoding/Input.txt", "rt", stdin);
//
//    vector<int> v;
//    vector<Pair> result;
//    int n, m, x, y, position = 0;
//    cin>>n;
//    cin>>m;
//    cin>>x;
//    cin>>y;
//
//    for(int i = 0; i < n; i++) {
//        int temp;
//        cin>>temp;
//        v.push_back(temp);
//    }
//
//    for (int k = 0; k < m; k++) {
//        if (position >= n) {
//            break;
//        }
//
//        int temp;
//        cin>>temp;
//
//        for (int i = position; i < n; i++) {
//            if (temp <= v[i] + y && temp >= v[i] - x) {
//                position = i + 1;
//                Pair pair;
//                pair.u = i + 1;
//                pair.v = k + 1;
//                result.push_back(pair);
//                break;
//            }
//
//            if (temp < v[i] - x) {
//                break;
//            }
//            else {
//                position = i + 1;
//            }
//        }
//    }
//
//    cout<<result.size() << endl;
//
//    for (int i = 0; i < result.size(); i++) {
//        cout<<result[i].u;
//        cout<<" ";
//        cout<<result[i].v << endl;
//    }
//
//
//    return 0;
//}

//int main() {
//    
//    vector<int> v;
//    int n, a, b;
//
//    cin>>n;
//    cin>>a;
//    cin>>b;
//
//    for(int i = 0; i < n; i++) {
//        int temp;
//        cin>>temp;
//        v.push_back(temp);
//    }
//    
//    sort(v.begin(), v.end());
//
//    if (n == 2) {
//        if (v[0] != v[1]) {
//            cout<<v[1] - v[0];
//        }
//        else {
//            cout<<0;
//        }
//        return 0;
//    }
//    
//    
//    int temp = v[b - 1];
//    
//    if (v[b] > temp) {
//        cout<<v[b] - temp;
//    }
//    else {
//        cout<<0;
//    }
//    return 0;
//}

//int main() {
//    
//    vector<int> v;
//    int k, sum = 0, month = 0;
//    
//    cin>>k;
//    
//    for(int i = 0; i < 12; i++) {
//        int temp;
//        cin>>temp;
//        v.push_back(temp);
//    }
//    
//    sort(v.begin(), v.end(), greater<int>());
//    
//    if (k == 0 ) {
//        cout<<0;
//        return 0;
//    }
//    
//    for (int i = 0; i < 12; i++) {
//        sum+= v[i];
//        month++;
//        if (sum >= k) {
//            break;
//        }
//    }
//    
//    if (sum >= k) {
//        cout<<month;
//    }
//    else {
//        cout<<-1;
//    }
//   
//    return 0;
//}


//int main() {
//    
//    vector<int> v;
//    int n, r, l;
//    
//    cin>>n;
//    int first;
//    cin>>first;
//    v.push_back(first);
//
//    for(int i = 1; i < n; i++) {
//        int temp;
//        cin>>temp;
//        v.push_back(temp);
//        
//        if (temp < v[i-1]) {
//            
//        }
//    }
//    
//    if (is_sorted(v.begin(), v.end())) {
//        cout<<"yes"<<endl;
//        cout<<"1 1";
//        return 0;
//    }
//    else {
//        
//    }
//    
//    sort(v.begin(), v.end(), greater<int>());
//    
//    return 0;
//}


//int main() {
//    
//    vector<int> v;
//    int n, r, l;
//    
//    cin>>n;
//    int first;
//    cin>>first;
//    v.push_back(first);
//    
//    for(int i = 1; i < n; i++) {
//        int temp;
//        cin>>temp;
//        v.push_back(temp);
//        
//        if (temp < v[i-1]) {
//            
//        }
//    }
//    
//    if (is_sorted(v.begin(), v.end())) {
//        cout<<"yes"<<endl;
//        cout<<"1 1";
//        return 0;
//    }
//    else {
//        
//    }
//    
//    sort(v.begin(), v.end(), greater<int>());
//    
//    return 0;
//}


//--------test-----

//int main() {
//
//    vector<int> v;
//    
//    int n, k;
//    cin>>n;
//    cin>>k;
//    
//    
//    for (int i = 0; i < n; i++) {
//        int temp;
//        cin>>temp;
//        
//        if (temp <= 2*k) {
//            v.push_back(temp);
//        }
//        else {
//            int nguyen = temp/(2*k);
//            int du = temp%(2*k);
//            for (int t = 0; t < nguyen; t++) {
//                v.push_back(2*k);
//            }
//            
//            if (du != 0) {
//                v.push_back(du);
//            }
//        }
//    }
//    
//    sort(v.begin(), v.end(), greater<int>());
//    
//    int days = 0, position = -1;
//    
//    for (int i = 0; i < v.size(); i++) {
//        if (v[i] <= 2*k && v[i] > k) {
//            days++;
//        }
//        else {
//            position = i;
//            break;
//        }
//    }
//    
//    if (position != -1) {
//        long size = v.size() - position;
//        days += size/2 + size%2;
//    }
//    
//    cout<<days;
//    
//    
//    return 0;
//}


//int main() {
//    
//    vector<int> v;
//    
//    int b1, q, l, m;
//    cin>>b1;
//    cin>>q;
//    cin>>l;
//    cin>>m;
//    
//    for (int i = 0; i < m; i++) {
//        int temp;
//        cin>>temp;
//        v.push_back(temp);
//    }
//    
//    int result = 1;
//    int f = b1;
//    int count = 0;
//    bool first = true;
//
//    while (abs(f) < l) {
//        
//        bool flag = false;
//        for (int i = 0; i < m; i++) {
//            if (f == v[i]) {
//                flag = true;
//                break;
//            }
//        }
//        
//        if (first == false && (b1 == 0 || b1 == -1 || b1 == 1 || q == 0 || q == -1 || q == 1)) {
//            
//            if (q == 1 || b1 == 1) {
//                
//            }
//            else {
//                
//            }
//            
//            if (count == 1) {
//                result = -1;
//                break;
//            }
//            else {
//                result = 0;
//                break;
//            }
//        }
//        else {
//            result = 1;
//            b1 = f;
//            f = b1*q;
//            if (flag == false) {
//                count += 1;
//            }
//
//        }
//        
//        first = false;
//    }
//    
//    if (result == -1) {
//        cout<<"inf";
//    }
//    else if (result == 0) {
//        cout<<0;
//    }
//    else {
//        cout<<count;
//    }
//    
//    
//    return 0;
//}


////-----------------BFS-------------

#define MAX 100
int V, E;
bool visited[MAX];
list<int> graph[MAX];
int path[MAX];

void BFS(int s) {
    
    for(int i = 0; i < V; i++) {
        visited[i] = false;
        path[i] = -1;
    }
    
    queue<int> q;
    visited[s] = true;
    q.push(s);
    list<int>::iterator i;
    
    while (!q.empty()) {
        s = q.front();
        q.pop();
        for(i = graph[s].begin(); i != graph[s].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
                path[*i] = s;
            }
        }
    }
}

bool PrintPath(int s, int f, int back[]) {
    int b[MAX];
    int m = 0;
    while (1) {
        b[m++] = f;
        f = back[f];
        
        if(f == s) {
            b[m++] = s;
            break;
        }
        
        if (f == -1) {
            return false;
        }
    }
    
    for (int i = m - 1; i >= 0; i--) {
        cout<<b[i]<<" ";
    }
    return true;
    
}

int main() {
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
    int u, v;
    cin>>V>>E;
    for (int i = 0; i < E; i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int s = 1;
    int d = 4;
    
    BFS(s);
    cout<<PrintPath(s, d, path);
    return 0;
}

//-----------------DFS-------------

//#define MAX 100
//int V, E;
//bool visited[MAX];
//list<int> graph[MAX];
//int path[MAX];
//
//void DFS(int src) {
//    
//    for(int i = 0; i < V; i++) {
//        visited[i] = false;
//        path[i] = -1;
//    }
//    
//    stack<int> s;
//    visited[src] = true;
//    s.push(src);
//    list<int>::iterator i;
//    
//    while (!s.empty()) {
//        src = s.top();
//        s.pop();
//        for(i = graph[src].begin(); i != graph[src].end(); i++) {
//            if (!visited[*i]) {
//                visited[*i] = true;
//                s.push(*i);
//                path[*i] = src;
//            }
//        }
//    }
//}
//
//void PrintPath(int s, int f, int back[]) {
//    int b[MAX];
//    int m = 0;
//    while (1) {
//        b[m++] = f;
//        f = back[f];
//        
//        if(f == s) {
//            b[m++] = s;
//            break;
//        }
//        
////        if (f == -1) {
////            return false;
////        }
//    }
//    
//        for (int i = m - 1; i >= 0; i--) {
//            cout<<b[i]<<" ";
//        }
////    return true;
//    
//}
//
////int main() {
////    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
////    int u, v;
////    cin>>V>>E;
////    for (int i = 0; i < E; i++) {
////        cin>>u>>v;
////        graph[u].push_back(v);
////        graph[v].push_back(u);
////    }
////
////    
////    int s = 0;
////    int d = 5;
////    
////    BFS(s);
////    PrintPath(s, d, path);
////    return 0;
////}
//
//int main() {
//    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
//    int u, v;
//    cin>>V>>E;
//    for (int i = 0; i < E; i++) {
//        cin>>u>>v;
//        graph[u].push_back(v);
//        graph[v].push_back(u);
//    }
//    
//    
//    int s = 0;
//    int d = 5;
//    
//    DFS(s);
//    PrintPath(s, d, path);
//    return 0;
//}



