#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归方法，dfs遍历二叉树，然后再交换子节点
class Solution1
{
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        if(root==NULL) return NULL;
        TreeNode *left = mirrorTree(root->left);
        TreeNode *right = mirrorTree(root->right);
        // 回溯部分
        root->left = right;
        root->right = left;
        return root;
    }
};

// 辅助栈方法
class Solution2
{
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *cur = stack.top();
            stack.pop();
            // 将子节点压栈时，要提前判断子节点是否为空；
            // 另外需要注意的点是，是否会引入奇怪的空指针（末尾的NULL）
            if (cur->left)
                stack.push(cur->left);
            if (cur->right)
                stack.push(cur->right);
            TreeNode *temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
        }
        return root;
    }
};

int main(){
    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->right = new TreeNode(7);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(9);
    Solution2 sol2;
    head = sol2.mirrorTree(head);
    return 0;
}