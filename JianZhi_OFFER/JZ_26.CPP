#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归嵌套的操作
// 1.先通过先序遍历A，找到和B相同的根节点；（如果没找到，A和B中一个为NULL，直接false） 
// 2.找到根节点后，递归比较两个二叉树是否相同；（由于B去匹配A，所以当B为空，证明匹配完全，A为空或者A和B结点值不同，则匹配失败）
class Solution
{
public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if(A==NULL||B==NULL) return false;
        return recur(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool recur(TreeNode *A, TreeNode *B){
        // 此时不论A是否为空，只要B为空，就是匹配成功
        if(B==NULL) return true;
        if(A==NULL||A->val!=B->val) return false;
        return recur(A->left,B->left) && recur(A->right,B->right);
    }
};