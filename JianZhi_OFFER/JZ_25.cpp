#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 归并排序的merge算法,但是链表形式的归并需要一个【虚拟头结点】；
// 每个分支执行完后，记得要移动指针，循环结束后，将非空的链表加上；
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(l1&&l2){
            if(l1->val<=l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else if (l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1?l1:l2;
        return dummy->next;
    }
};