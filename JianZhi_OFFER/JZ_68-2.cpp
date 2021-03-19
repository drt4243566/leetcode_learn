#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 利用后序遍历递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 越过叶节点和刚好等于p,q返回本身 -- 这里暗含了如果刚好p为q的父节点，则递归到p就返回，在其他子树上找不到q，最终返回的仍然是p
        if(root==nullptr||p==root||q==root) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        // 这里包括四种情况：
        /*1. left和right都为空，则返回空；
          2. 当left和right同时不为空，则为公共祖先；
          3. 当left为空，但是right不为空，说明p,q都不在左子树当中，返回right;
            3-1 p和q中有一个在右子树，right指向这个数；
            3-2 p和q两个都在右子树，right已经是最近公共节点；
          4. 当right为空，和3同理；
            */
        if(left==nullptr) return right;
        if(right==nullptr) return left;
        // 当左右子树都不为空的时候，说明p,q在root节点的两侧，才返回当前节点为公共节点
        return root;
    }
};

// 进一步学习k个节点的公共祖先节点问题
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        k=2;
        dfs(root,p,q);
        return res;
    }
    // 核心的思路是如果某个节点遍历完左右子树之后,k值从k变成了0，表明这个节点为我们需要找的节点
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr||k==0) return;
        int k_old = k;
        if(root->val==p->val||root->val==q->val) k--;
        dfs(root->left,p,q);
        dfs(root->right,p,q);
        // 这里的res也很关键，保证回溯的过程中取到【最近的】祖先节点
        if(k_old==2&&k==0&&res==nullptr) res=root;
    }
private:
    int k;
    TreeNode* res;
};
