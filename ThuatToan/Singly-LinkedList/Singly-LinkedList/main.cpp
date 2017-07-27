#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <set>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class ListNode {

    Node* head = NULL;

public:
    Node* getHeadNode();
    void printList();
    void addNode(int data);
    void removeDuplicatesWithHasBuffer();
    void removeDuplicatesNoBuffer();
    int findKthToLast(Node *head, int k);
};


Node* ListNode::getHeadNode() {
    return head;
}

void ListNode::addNode(int data) {

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node *temp = head;

    if (head == NULL) {
        head = newNode;
    }
    else {
        while (temp->next != NULL ) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void ListNode::removeDuplicatesWithHasBuffer() {

    Node *temp = head;
    unordered_set<int> s;
    Node *previousNode = NULL;

    while (temp != NULL) {
        if (s.find(temp->data) != s.end()) {
            previousNode->next = temp->next;
        }
        else {
            s.insert(temp->data);
            previousNode = temp;
        }
        temp = temp->next;
    }
}

void ListNode::removeDuplicatesNoBuffer() {

    Node *temp = head;

    while (temp != NULL) {
        Node* runner = temp;

        while (runner->next != NULL) {
            if (runner->next->data == temp->data) {
                runner->next = runner->next->next;
            }
            else {
                runner = runner->next;
            }
        }

        temp = temp->next;
    }
}

int ListNode::findKthToLast(Node *head, int k) {

    if (head == NULL) {
        return 0;
    }

    int index = findKthToLast(head->next, k) + 1;

    if (index == k) {
        printf("%d th to last node is %d", k, head->data);
    }
    return index;
}

void ListNode::printList() {

    Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/TamLe/Documents/Input.txt", "rt", stdin);
#endif

    ListNode listNode;

    listNode.addNode(3);
    listNode.addNode(2);
    listNode.addNode(4);
    listNode.addNode(6);
    listNode.addNode(6);

//    listNode.removeDuplicatesWithHasBuffer();
    listNode.removeDuplicatesNoBuffer();

    listNode.findKthToLast(listNode.getHeadNode(), 3);

//    listNode.printList();

    return 0;
}
