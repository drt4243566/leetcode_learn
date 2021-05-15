#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* reverseList(Node* head){
    Node* pre = nullptr;
    Node* cur = head;
    while(cur){
        Node* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    // 此时cur已经位于null，因此pre指向原本的最后一个元素
    return pre;
}