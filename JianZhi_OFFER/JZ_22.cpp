#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

// 双指针法，考虑时应该从结束的临界状态考虑，当fast指针已经到达null，
class Solution1{
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head, *slow = head;
        // 快指针超前k个节点
        for(int i=0;i<k;i++){
            fast = fast->next;
        }
        while(fast!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

class Solution2{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        int n = 0;
        ListNode *cur = head;
        while (cur != NULL)
        {
            n++;
            cur = cur->next;
        }
        cur = head;
        while (n > k)
        {
            cur = cur->next;
            n--;
        }
        return cur;
    }
};