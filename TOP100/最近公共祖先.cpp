/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return recur(root, o1, o2)->val;
    }
    
    TreeNode* recur(TreeNode* root,int o1, int o2) {
        if(root==nullptr) return nullptr;
        if(root->val==o1 || root->val==o2){
            return root;
        }
        TreeNode* left = recur(root->left,o1,o2);
        TreeNode* right = recur(root->right,o1,o2);
        if(left&&right) return root;
        else return left?left:right;
    }
};

// 这道题目很妙，如果只是判断一个结点两侧的左右子树有没有结点，就是每次统计左侧和右侧的返回值
// 如果左右都存在，当前就是最近公共祖先
// 另一种可能是直接当前结点为o1或者o2，不需要继续向下找，直接返回当前结点就默认包含了另一个
// 目标值在自己子树中的可能；