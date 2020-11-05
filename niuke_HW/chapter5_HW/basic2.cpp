#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int value) : val(value), left(NULL), right(NULL) {}
    ListNode() : val(), left(), right() {}
};

// 判断搜索二叉树所需的信息
class info
{
public:
    bool isBST;
    int min;
    int max;
    info() : isBST(), min(), max() {}
    info(bool is, int mi, int ma) : isBST(is), min(mi), max(ma) {}
};

// 判断满二叉树需要的信息
class infoMan
{
public:
    int height;
    int nodes;
    infoMan(int h, int n) : height(h), nodes(n) {}
    infoMan() {}
};

// 判断平衡二叉树传递的信息
class infoBal
{
public:
    bool isBal;
    int height;
    infoBal() {}
    infoBal(bool isBalance, int h) : isBal(isBalance), height(h) {}
};

// 寻找公共祖先节点的信息
class infoFather
{
public:
    infoFather() {}
    infoFather(bool f1, bool f2, ListNode *ans) : findO1(f1), findO2(f2), findAns(ans) {}
    bool findO1;
    bool findO2;
    ListNode *findAns;
};

// 二叉树的初始化
ListNode *init(ListNode *cur)
{
    cur->left = new ListNode(2);
    cur->right = new ListNode(6);
    cur->left->left = new ListNode(1);
    cur->left->right = new ListNode(3);
    //cur->right->left = new ListNode(5);
    cur->right->right = new ListNode(7);
    return cur;
}

int absNum(int x)
{
    return x > 0 ? x : -x;
}

// 判断是否为搜索二叉树(Binaray search tree)
info *isBSTTree(ListNode *cur)
{
    // 区分清楚输入参数和返回参数在递归中的不同作用
    // 这里要使用指针类型作为返回
    // 搜索二叉树的判断，左右子树都是BST，左子树最大值，右子树最小值
    if (cur == NULL)
    {
        return NULL;
    }
    else
    {
        info *leftdata = isBSTTree(cur->left);
        info *rightdata = isBSTTree(cur->right);
        int minData = cur->val;
        int maxData = cur->val;
        if (leftdata != NULL)
        {
            minData = min(minData, leftdata->min);
            maxData = max(maxData, leftdata->max);
        }
        if (rightdata != NULL)
        {
            minData = min(minData, rightdata->min);
            maxData = max(maxData, rightdata->max);
        }
        bool BST = (leftdata != NULL ? (leftdata->isBST && leftdata->max < cur->val) : true) && (rightdata != NULL ? (rightdata->isBST && rightdata->min > cur->val) : true);
        return new info(BST, minData, maxData);
    }
}

// 判断是否为满二叉树
infoMan *isManBT(ListNode *head)
{
    if (head == NULL)
    {
        return new infoMan(0, 0);
    }
    infoMan *leftMan = isManBT(head->left);
    infoMan *rightMan = isManBT(head->right);
    int height = max(leftMan->height, rightMan->height) + 1;
    int nodes = leftMan->nodes + rightMan->nodes + 1;
    return new infoMan(height, nodes);
}

bool isFullTree(ListNode *head)
{
    if (head == NULL) // 其实可能不是很需要判断，上面的函数在空的时候直接返回（0,0）
        return true;
    infoMan *res = isManBT(head);
    int res_h = res->height;
    int res_n = res->nodes;
    return (1 << res_h) - 1 == res_n; //判断是不是满二叉树的公式: n=2^H-1
}

// 判断平衡二叉树
infoBal *isBalanced(ListNode *head)
{
    if (head == NULL)
    {
        return new infoBal(true, 0);
    }
    infoBal *leftInfo = isBalanced(head->left);
    infoBal *rightInfo = isBalanced(head->right);
    int height = max(leftInfo->height, rightInfo->height) + 1;
    bool isBal = leftInfo->isBal && rightInfo->isBal && (absNum(rightInfo->height - leftInfo->height) < 2);
    return new infoBal(isBal, height);
}

// 寻找两个节点的公共祖先
infoFather *findFather(ListNode *head, ListNode *O1, ListNode *O2)
{
    if (head == NULL)
    {
        return new infoFather(false, false, NULL);
    }
    infoFather *leftinfo = findFather(head->left, O1, O2);
    infoFather *rightinfo = findFather(head->right, O1, O2);
    // 情况1：左右子树直接存在公共祖先
    if (leftinfo->findAns != NULL)
    {
        return new infoFather(true, true, leftinfo->findAns);
    }
    if (rightinfo->findAns != NULL)
    {
        return new infoFather(true, true, rightinfo->findAns);
    }
    // 情况2：左右子树各自包含O1或O2中的一个,根节点为祖先节点
    if ((leftinfo->findO1 && rightinfo->findO2) || (leftinfo->findO2 && rightinfo->findO1))
    {
        return new infoFather(true, true, head);
    }
    // 情况3：左右子树只包含O1和O2中的一个，根节点刚好为另一个节点
    if (leftinfo->findO1 || rightinfo->findO1)
    {
        if (head == O2)
        {
            return new infoFather(true, true, head);
        }
        else
        {
            return new infoFather(true, false, NULL);
        }
    }
    if (leftinfo->findO2 || rightinfo->findO2)
    {
        if (head == O1)
        {
            return new infoFather(true, true, head);
        }
        else
        {
            return new infoFather(false, true, NULL);
        }
    }
    // 情况4：左右子树都没有O1和O2
    return new infoFather(head == O1, head == O2, NULL);
}

// 判断是否为完全二叉树
bool isComplete(ListNode *head)
{
    if (head == NULL)
    {
        return true;
    }
    long leaf(0);
    queue<ListNode *> q;
    q.push(head);
    while (!q.empty())
    {
        ListNode *cur = q.front();
        q.pop();
        ListNode *leftTree = cur->left;
        ListNode *rightTree = cur->right;
        // (1) 右树存在左树不存在和 (2) 右树不存在的情况后全部为叶子节点
        if ((leaf && (leftTree || rightTree)) || (leftTree == NULL && rightTree))
        {
            return false;
        }
        if (leftTree != NULL)
        {
            q.push(leftTree);
        }
        if (rightTree != NULL)
        {
            q.push(rightTree);
        }
        if (leftTree == NULL || rightTree == NULL)
        {
            leaf = 1;
        }
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(4);
    ListNode *cur = init(head);
    /*info *sousuoBT = isBSTTree(cur);
    cout << "是否搜索二叉树：" << sousuoBT->isBST << endl;
    cout << "是否满二叉树：" << isFullTree(cur) << endl;
    cout << "是否平衡：" << isBalanced(cur)->isBal << endl;
    cout << "是否完全二叉树：" << endl;
    ListNode *o1 = cur->left->left;
    ListNode *o2 = cur->right->left;
    cout << "公共祖先：" << findFather(cur, o1, o2)->findAns->val << endl;
    */
    printf("%d\n", isComplete(cur) ? 1 : 0);
    return 0;
}