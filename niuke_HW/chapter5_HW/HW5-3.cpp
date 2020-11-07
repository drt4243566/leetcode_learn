#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int value) : val(value), left(NULL), right(NULL) {}
    ListNode() : val(), left(), right() {}
};

// 二叉树的初始化
ListNode *init(ListNode *cur)
{
    cur->left = new ListNode(2);
    cur->right = new ListNode(6);
    cur->left->left = new ListNode(1);
    cur->left->right = new ListNode(3);
    cur->right->left = new ListNode(5);
    cur->right->right = new ListNode(7);
    return cur;
}

class solution
{
public:
    vector<int> inOrderTravel(ListNode *head)
    {
        vector<int> res;
        stack<ListNode *> stk;
        while (head || !stk.empty())
        {
            if (head != NULL)
            {
                stk.push(head);
                head = head->left;
            }
            else
            {
                head = stk.top();
                stk.pop();
                res.push_back(head->val);
                head = head->right;
            }
        }
        return res;
    }
};

int main()
{
    ListNode *head = new ListNode(4);
    ListNode *cur = init(head);
    vector<int> res;
    solution sol;
    res = sol.inOrderTravel(cur);
    for (int &i : res)
    {
        cout << i << "-";
    }
    cout << endl;
    return 0;
}