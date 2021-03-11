#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 出发点是搜索二叉树的中序遍历是一个递增序列，所以题目要求的第k大的数字代表的是从大到小的递减排列后的第k个（需要完成右中左的倒序操作）
// 三个关键步骤： 1.递归时必须计数，k--； 2.递归到k=0时，将此节点的值保存在res当中； 3.在k=0时，立刻终止递归；
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        key = k;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(root==NULL) return;
        // 反向中序遍历：右-中-左
        dfs(root->right);
        if(key==0) return;
        if(--key==0) {res = root->val;}
        dfs(root->left);
    }
private:
    // 这两手成员变量非常关键,不会随着递归的回溯过程发生变化
    int key;
    int res;
};

// 离谱版本
class Solution2{
public:
    int kthLargest(TreeNode* root, int k) {
        key = k-1;
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(root==NULL) return;
        // 反向中序遍历：右-中-左
        dfs(root->right);
        // 问题主要在这个位置，在返回res之后继续回溯，需要全部直接return
        if(key==0) {
            res = root->val;
            key--;
            return;
        }
        else if(key<0) return;
        key--;
        dfs(root->left);
    }
private:
    // 这两手成员变量非常关键,不会随着递归的回溯过程发生变化
    int key;
    int res;
};
int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->left = NULL;
    root->right->left = NULL;
    root->right->right = NULL;
    Solution sol1;
    cout << sol1.kthLargest(root,1)<<endl;
    Solution2 sol2;
    cout << sol2.kthLargest(root,1);
}