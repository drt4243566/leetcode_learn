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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            // for循环的初始化是精髓，利用初始化记录每层结点个数
            // 虽然在进出队列时，队列长度不断发生变化，但是可以用循环区分
            for(int i=q.size();i>0;i--){
                TreeNode* cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};