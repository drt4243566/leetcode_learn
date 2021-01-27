#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 错误想法，忽略了第二层时对于对称性的要求
class WrongSol
{
public:
    bool isSymmetric(TreeNode *root)
    {
        bool res = false;
        if(root==NULL) return true;
        if(root->left==NULL&&root->right==NULL) return true;
        else if(root->left==NULL||root->right==NULL) return false;
        else{
            res = isSymmetric(root->left) && isSymmetric(root->right) && (root->left->val==root->right->val);
        }
        return res;
    }
};

// 对称二叉树，任意的两个对称节点L和R，一定有：
// 1.对称节点的值相等； 2.L的左节点和R的右节点相等； 3.L的右节点和R的左节点相等；
// 递归的关键在于【一对对称节点L和R】

class Solution2{
public:
    bool isSymmetric(TreeNode *root){
        if(root==NULL) return true;
        return recur(root->left,root->right);
    }
    bool recur(TreeNode* L,TreeNode* R){
        if(L==NULL&&R==NULL) return true;
        if(L==NULL||R==NULL||L->val!=R->val) return false;
        return recur(L->left,R->right)&&recur(L->right,R->left);
    }
};