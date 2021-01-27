#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pathRecur(root,sum);
        return res;
    }
    void pathRecur(TreeNode* root, int rest){
        if(root==NULL) return;
        rest -= root->val;
        PathList.push_back(root->val);
        if(rest==0 && root->left==NULL && root->right==NULL) res.push_back(PathList);
        pathRecur(root->left,rest);
        pathRecur(root->right,rest);
        // 回溯法到这里必须去掉加入PathList的元素
        PathList.pop_back();
    }
private:
    vector<int> PathList;
    vector<vector<int>> res;
};