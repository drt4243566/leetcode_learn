#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        if(root==NULL) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            if (temp!=NULL) res.push_back(temp->val);
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        return res;
    }
};