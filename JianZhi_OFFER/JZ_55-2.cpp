#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 另一种从顶至底的思路，相当直接
class Solution2{
public:
     bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        return abs(depth(root->left)-depth(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right);
    }
    // 单纯得到子树的深度
    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
};