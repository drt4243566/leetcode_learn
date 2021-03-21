#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 重建二叉树，递归解法只适用于二叉树没有重复节点值的情况，实际上一个先序序列的信息已经足够重建，只是缺少二叉树子树如何划分

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 在先序遍历序列的基础上，对中序序列进行划分
        this->preorder = preorder;
        for(int i=0;i<inorder.size();i++){
            // 主要为了查找数字对应的位置
            dic[inorder[i]] = i;
        }
        return buildRecur(0, 0 ,inorder.size() - 1);
    }

private:
    vector<int> preorder;
    unordered_map<int,int> dic;         // 哈希表查询加速
    //buildRecur对应的二叉树，root作为根节点，子节点的范围：[left,right]
    TreeNode *buildRecur(int root, int left, int right)
    {
        if(left>right) return NULL;     // 可以在叶节点下都添加NULL指针
        TreeNode *node = new TreeNode(preorder[root]);
        int i = dic[preorder[root]];
        node->left = buildRecur(root+1, left ,i-1);
        node->right = buildRecur(root+i-left+1, i+1 ,right);
        return node;
    }
};

// 超级迷的迭代写法
class Solution1{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        if(preorder.size()==0) return nullptr;
        stack<TreeNode*> s;
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *cur = root;

        for(int i=1,j=0; i<preorder.size(); i++){
            // 情况1  左子树
            if(cur->val != inorder[j]){
                cur->left = new TreeNode(preorder[i]);
                s.push(cur);
                cur = cur->left;
            }
            // 情况2  右子树
            else{
                j++;
                while(!s.empty()&&s.top()->val==inorder[j]){
                    cur = s.top();
                    s.pop();
                    j++;
                }
                cur->right = new TreeNode(preorder[i]);
                cur = cur->right;
            }
        }
        return root;
    }
};

void printNode(TreeNode *head){
    if(head==NULL) return;
    cout << head->val << " ";
    printNode(head->left);
    printNode(head->right);
}

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution sol;
    Solution1 sol1;
    TreeNode *bTree = sol.buildTree(preorder, inorder);
    printNode(bTree);
    cout << endl;
    return 0;
}