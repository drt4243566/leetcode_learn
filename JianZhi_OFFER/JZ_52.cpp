#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* L1 = headA;
        ListNode* L2 = headB;
        // 这里的判断条件是L1!=NULL，之所以不是L1->next，是由于当两个链表没有公共节点时，最终需要停留在
        // NULL节点的位置，用作函数的返回值；
        // 相当于 2->5->8->null 作为一个完整的链表
        while(L1!=L2){
            L1 = L1!=NULL?L1->next:headB;
            L2 = L2!=NULL?L2->next:headA;
        }
        return L1;
    }
};
