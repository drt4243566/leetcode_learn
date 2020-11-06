#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    //cur->left->right = new ListNode(3);
    //cur->right->left = new ListNode(5);
    //cur->right->right = new ListNode(7);
    return cur;
}

class Tree2Sequence
{
public:
    string ToSequence(ListNode *root)
    {
        string s = "";
        if (root != NULL)
        {
            stringstream ss;
            string temp;
            ss << root->val;
            ss >> temp;
            s += "(" + temp;
            s += ToSequence(root->left);
            s += ToSequence(root->right);
            s += ")";
        }
        return s;
    }
};

int main()
{
    ListNode *head = new ListNode(4);
    ListNode *cur = init(head);
    Tree2Sequence a;
    cout << a.ToSequence(cur) << endl;
}