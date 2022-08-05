#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root){
    if(root==nullptr) return {};
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int len = q.size();
        vector<int> level;
        for(int i=0;i<len;i++){
            TreeNode* temp = q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left!=nullptr) q.push(temp->left);
            if(temp->right!=nullptr) q.push(temp->right);
        }
        res.push_back(level);
    }
    return res;
}