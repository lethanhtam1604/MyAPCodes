#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
#define MAX 10
bool result = false;

struct Node {
    struct Node *child[MAX];
    int countLeaf;
};

struct Node *newNode() {
    struct Node *node = new struct Node;
    node->countLeaf = 0;
    for(int i = 0; i < MAX; i++) {
        node->child[i] = NULL;
    }
    return node;
}

void addWord(struct Node *root, string s) {
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++) {
        ch = s[i] - '0';
        
        if(temp->countLeaf > 0) {
            result = true;
        }
        
        if(temp->child[ch] == NULL) {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countLeaf++;
    
    for(int i = 0; i < MAX; i++) {
        if(temp->child[i]) {
            result = true;
        }
    }
}

bool isEmpty(struct Node *pNode) {
    
    for(int i = 0; i < MAX; i++) {
        if(pNode->child[i] != NULL) {
            return false;
        }
    }
    return true;
}


bool leafNode(struct Node *pNode) {
    return (pNode->countLeaf != 0);
}

bool removeWord(struct Node *root, string s, int level, int len) {
    if (!root) {
        return false;
    }
    int ch = s[level] - '0';
    
    if (level == len) {
        root->countLeaf--;
    }
    else {
        removeWord(root->child[ch], s, level + 1, len);
    }
    
    if (!leafNode(root) && isEmpty(root)) {
        delete root->child[ch];
        root->child[ch] = NULL;
        return true;
    }
    
    return false;
}

void deleteTrie(Node *root) {
    if (root) {
        for (int i = 0; i < 10; i++) {
            deleteTrie(root->child[i]);
            root->child[i] = NULL;
        }
        delete root;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/thanhtamle/Documents/INPUT.txt", "rt", stdin);
#endif
    
    int t, n;
    string s;
    cin>>t;
    
    for(int k = 1; k <= t; k++) {
        struct Node *root = newNode();
        result = false;
        
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>s;
            addWord(root, s);
        }
        
        if (result == true) {
            printf("Case %d: NO\n", k);
        }
        else {
            printf("Case %d: YES\n", k);
        }
        
        deleteTrie(root);
    }
    
    return 0;
}
