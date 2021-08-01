#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

// 判断单链表是否有环
bool isRing(Node* head){
    Node* fast=head,*slow=head;
    while(slow!=nullptr&&fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

//寻找环的入口
Node* findLoopStart(Node* head){
    Node* fast=head,*slow=head;
    while(slow!=nullptr&&fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }
    // 此时无环
    if(slow!=fast) return nullptr;
    Node* ptr = head;
    // 确定有环的情况下，不需要判空
    while(ptr!=slow){
        ptr = ptr->next;
        slow = slow->next;
    }
    // 当二者节点再次相遇即为入口
    return ptr;
}

//寻找环的长度
Node* findLoopStart(Node* head){
    Node* fast=head,*slow=head;
    while(slow!=nullptr&&fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }
    // 此时无环
    if(slow!=fast) return 0;
    Node* ptr = slow;
    int res=0;
    // 确定有环的情况下，不需要判空
    while(ptr!=slow){
        ptr = ptr->next;
        res++;
    }
    // 当二者节点再次相遇即为入口
    return ptr;
}
int main(){
    cout << "my 神";
    return 0;
}