#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 二叉搜索树的最近公共祖先问题
// 迭代法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=nullptr){
            // p,q都在root的右子树里面
            if(root->val<p->val&&root->val<q->val)  root = root->right;
            // 均在左子树当中
            else if(root->val>p->val&&root->val>q->val) root = root->left;
            // 一左一右
            else break;
        }
        return root;
    }
};
// 递归求法
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // p,q都在root的右子树里面
        if(root->val<p->val&&root->val<q->val)  return lowestCommonAncestor(root->right,p,q);
        if(root->val>p->val&&root->val>q->val)  return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};
/* 公共祖先节点的条件有三种情况：
   1. p<root<q或者q<root<p;
   2. p和q中的一个等于root，另一个作为子树
   
   由于题目中说明p和q一定在二叉树中，因此不会出现越过叶节点的情况*/