#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class PalindromeList
{
public:
    bool checkPalindrome(ListNode *A)
    {
        ListNode *f(A), *s(A);
        // 快慢指针遍历到终点位置时，慢指针正好指向序列的中点位置
        while (f->next != NULL && f->next->next != NULL)
        {
            f = f->next;
            s = s->next;
        }
        f = A;
        invertLink(f);
    }
    void invertLink(ListNode *B)
    {
        ListNode *cur(B), *pre(B), *t;
        if (cur == NULL && cur->next == NULL)
        {
            return;
        }
        cur = pre->next;
        pre->next = NULL;
        while (cur->next != NULL)
        {
            t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
    }
};

int main()
{
}