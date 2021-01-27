#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

// 常规的迭代解法
// 1.需要注意最后返回pre指针，原本的cur指针指向null；
// 2.迭代法使用三指针，pre,cur和next，循环的终止条件是cur为空；

class Solution1
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL, *cur = head, *next = NULL;
        while(cur!=NULL){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

// 递归法
// 完全利用递归的【回溯部分】进行递推，当只剩下一个元素的时候，不需要翻转，直接返回，关键这个返回值作为翻转链表的头结点；
// 中间节点情况，在每次函数返回的过程中，都让下一个结点的指针指向自己，自己指向NULL；
// 在回溯过程中，由于函数堆栈的储存作用，可以保证当前节点不断回退，直到全部翻转完成；

class Solution2{
public:
    ListNode* reverseList(ListNode* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};

int main(){
    return 0;
}