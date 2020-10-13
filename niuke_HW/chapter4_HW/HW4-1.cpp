#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class PalindromeList
{
public:
    bool checkPalindrome(ListNode *A)
    {
        if (A == NULL || A->next == NULL)
            return true;
        ListNode *f(A), *s(A);
        // 快慢指针遍历到终点位置时，慢指针正好指向序列的中点位置
        while (f->next != NULL && f->next->next != NULL)
        {
            f = f->next->next; // 区分快指针
            s = s->next;
        }
        s = invertLink(s);
        f = A;
        while (f != s)
        {
            if (f->val != s->val)
                return false;
            f = f->next;
            s = s->next;
        }

        return true;
    }

    ListNode *invertLink(ListNode *B)
    {
        ListNode *cur(B), *pre(B), *t;
        if (cur == NULL || cur->next == NULL)
        {
            return B;
        }
        cur = pre->next;
        pre->next = NULL;
        while (cur != NULL)
        {
            t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre; // 在终止位置，cur和t都位于NULL的位置上，pre指向原本最后一个元素的位置
    }
};

int main()
{
    PalindromeList palind;
    int huiwen[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    ListNode *head = new ListNode(huiwen[0]), *cur = head;
    for (size_t i = 1; i < 9; i++)
    {
        cur->next = new ListNode(huiwen[i]);
        cur = cur->next;
    }
    //翻转链表
    //head = palind.invertLink(head);
    //判断回文
    bool isPalindrome = palind.checkPalindrome(head);
    //打印链表
    cur = head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    cout << isPalindrome;
}