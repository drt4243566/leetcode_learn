/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   //使用自顶向下的递归方法
    /*int height(TreeNode* x){
        if(x==NULL){
            return 0;
        }
        return max(height(x->left),height(x->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        else{
            return isBalanced(root->left)&&isBalanced(root->right)&&abs(height(root->left)-height(root->right))<2;
        }
    }*/

    //自下而上递归，使用height为-1来表示非平衡的情况
    int height(TreeNode* x){
        if(x==NULL)
            return 0;
        int leftHeight=height(x->left);
        int rightHeight=height(x->right);
        if(leftHeight==-1||rightHeight==-1||abs(leftHeight-rightHeight)>1){
            return -1;
        }else{
            return max(leftHeight,rightHeight)+1;
        }
    }
    bool isBalanced(TreeNode* root){
        return height(root)>=0;
    }
};

//可以将求左右子树的高度直接放在条件判断语句当中，这样如果左子树为不平衡的情况，右子树不必进行递归调用