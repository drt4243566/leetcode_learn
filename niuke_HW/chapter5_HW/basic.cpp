#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int value) : val(value), left(NULL), right(NULL) {} //不能用引用参数，这里要直接赋值
    ListNode() : val(), left(), right() {}
};

// 二叉树的初始化
ListNode *init(ListNode *cur)
{
    cur->left = new ListNode(2);
    cur->right = new ListNode(3);
    cur->left->left = new ListNode(4);
    cur->left->right = new ListNode(5);
    cur->right->left = new ListNode(6);
    cur->right->right = new ListNode(7);
    return cur;
}

//先序遍历二叉树(递归)
void pre(ListNode *head)
{
    if (head == NULL)
        return;
    cout << head->val << " ";
    pre(head->left);
    pre(head->right);
}

//先序遍历（非递归）
void nonRecursivePre(ListNode *head)
{
    if (head != NULL)
    {
        stack<ListNode *> stk;
        stk.push(head);
        cout << "NonRecursive:" << endl;
        while (!stk.empty())
        {
            ListNode *cur = stk.top();
            stk.pop();
            cout << cur->val << " ";
            if (cur->right != NULL)
            {
                stk.push(cur->right);
            }
            if (cur->left != NULL)
            {
                stk.push(cur->left);
            }
        }
        cout << endl;
    }
}

//后序遍历二叉树(递归)
void proOrder(ListNode *head)
{
    if (head == NULL)
        return;
    proOrder(head->left);
    proOrder(head->right);
    cout << head->val << " ";
}

//后序遍历二叉树（非递归）
void proOrderUnRecur(ListNode *head)
{
    if (head != NULL)
    {
        stack<ListNode *> s1, s2;
        s1.push(head);
        while (!s1.empty())
        {
            ListNode *temp = s1.top();
            s2.push(temp);
            s1.pop();
            if (temp->left != NULL) //从s1弹出时候保持：中-右-左的顺序
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
        }
        while (!s2.empty()) //从s2弹出时，再逆序得到：左-右-中顺序
        {
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }
}

//中序遍历（递归）
void inOrder(ListNode *head)
{
    if (head != NULL)
    {
        inOrder(head->left);
        printf("%d ", head->val);
        inOrder(head->right);
    }
}

//中序遍历（非递归）
void inOrderUnRecur(ListNode *head)
{
    if (head != NULL)
    {
        ListNode *cur = head;
        stack<ListNode *> stk;
        while (!stk.empty() || cur != NULL)
        {
            if (cur != NULL) //将全部左子树遍历，放入栈中
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                ListNode *temp = stk.top();
                printf("%d ", temp->val);
                stk.pop();
                cur = temp->right;
            }
        }
    }
}

// 宽度优先遍历
void widthFirstOrder(ListNode *head)
{
    if (head != NULL)
    {
        queue<ListNode *> que;
        que.push(head);
        while (!que.empty())
        {
            ListNode *cur = que.front();
            que.pop();
            printf("%d ", cur->val);
            if (cur->left)
            {
                que.push(cur->left);
            }
            if (cur->right)
            {
                que.push(cur->right);
            }
        }
        printf("\n");
    }
}

//附带层数的层序遍历
void widthOrderwithlevel(ListNode *head)
{
    if (head != NULL)
    {
        int level(0);
        queue<ListNode *> que;
        unordered_map<ListNode *, int> mp;
        que.push(head);
        mp.insert(pair<ListNode *, int>(head, 1)); //层序表

        int clevel = 1;
        int cNodes = 0;

        while (!que.empty())
        {
            ListNode *cur = que.front();
            que.pop();
            level = mp.find(cur)->second; //C++里的find函数返回的是一个组合
            if (level == clevel)
            {
                cNodes++;
            }
            else
            {
                printf("level:%d,nodes:%d \n", clevel, cNodes);
                clevel++;
                cNodes = 1; //这里很特殊，由于已经弹出下一层的一个结点，初值设为1
            }

            printf("%d-(level:%d) ", cur->val, level);
            if (cur->left)
            {
                que.push(cur->left);
                mp[cur->left] = level + 1;
            }
            if (cur->right)
            {
                que.push(cur->right);
                mp[cur->right] = level + 1;
            }
        }
        printf("\n");
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *cur = init(head);
    /*cout << "先序遍历为：" << endl;
    pre(cur);
    cout << endl;
    nonRecursivePre(cur);
    cout << "后序遍历为：" << endl;
    proOrder(cur);
    cout << endl;
    proOrderUnRecur(cur);
    cout << "中序遍历为：" << endl;
    inOrder(cur);
    cout << endl;
    inOrderUnRecur(cur);*/
    cout << "宽度优先遍历为：" << endl;
    widthOrderwithlevel(cur);
    return 0;
}

/*  错误代码 —— 中序遍历（非递归）
*********************************
while循环里再嵌套一个while，其实完全可以把内部循环改成if/else
*********************************
while (!stk.empty())
        {
            while (cur != NULL) //将全部左子树遍历，放入栈中
            {
                stk.push(cur);
                cur = cur->left;
            }
            ListNode *temp = stk.top();
            printf("%d ", temp->val);
            stk.pop();
            cur = stk.top()->right;
        }
*/