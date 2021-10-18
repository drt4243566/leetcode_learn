class Solution {
public:
    int maxSum = INT_MIN;
    // 处理当前的子树，返回当前子树对于父节点能提供的最大路径和贡献
    // 内部其实包含两层情况，一种是最大路径和在父节点之上，那么当前子树只是做贡献；
    // 另一种情况是最大路径和在当前子树的内部，那就是必须包含当前的根节点，从左子树+根节点+右子树
    // 递归出口是当前为空树
    int dfs(TreeNode* root) {
        if(root==nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int innerSum = left+right+root->val;
        maxSum = max(innerSum,maxSum);
        int outSum = root->val+max(left,right);
        return max(outSum,0);
    }
    int maxPathSum(TreeNode* root){
        dfs(root);
        return maxSum;
    }
};