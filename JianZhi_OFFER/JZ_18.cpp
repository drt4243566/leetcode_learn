#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(NULL){}
};

// 经典双指针思路，依靠pre指针记录上一个位置的
class Solution1{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *cur = head->next;
        if (head->val == val)
        {
            return cur;
        }
        ListNode *pre = head;
        while (cur && cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        if (cur)
        {
            pre->next = cur->next;
        }
        return head;
    }
};

// 单指针玩法
class Solution2
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head == NULL)
            return NULL;
        if (head->val == val)
            return head->next;
        ListNode* cur = head;
        while (cur->next != NULL && cur->next->val != val)
            cur = cur->next;
        if (cur->next != NULL)
            cur->next = cur->next->next;
        return head;
    }
};

// 还可以设置虚拟结点
class Solution3
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        // 设置虚拟结点，放置在头结点之前，不用判断头结点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* cur = head;
        ListNode* pre = dummy;
        while(cur!=NULL){
            if(cur->val==val){
                pre->next = cur->next;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};

// 最离谱的递归方法
class Solution4
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        // 空链表没法删除结点
        if(head==NULL) return head;
        // 头结点刚好为所求结点,相当于删去此节点，直接返回下一个结点
        if(head->val==val) return head->next; 
        // 头结点不满足条件，返回当前节点，继续调用下一个结点
        head->next = deleteNode(head->next,val);
        return head;
    }
};

int main()
{
    return 0;
}
