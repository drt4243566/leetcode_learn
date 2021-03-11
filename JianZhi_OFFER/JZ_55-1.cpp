#include<vector>
#include<queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs后序遍历
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth,rightDepth)+1;
    }
};

// BFS层序遍历
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        int res=0;
        q.push(root);
        while(!q.empty()){
            res++;
            // 只需要一个当前层的长度，就可以控制完成本层的遍历行为
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }  
        }
        return res;
    }
};