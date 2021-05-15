#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int x):val(x){}
};

// 借助哨兵位
void deleteKthNode(Node* head,int k){
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* p=dummy,*q=dummy;
    // q在前，p在后
    while(k--){
        if(q==nullptr) return;
        q = q->next;
    }
    // 在q->next为NULL时，p指向倒数第k+1个节点
    while(q->next){
        p = p->next;
        q = q->next;
    }
    // 删除节点
    p->next = p->next->next;
    return;
}

// 摘自https://blog.csdn.net/m0_37257953/article/details/108372298