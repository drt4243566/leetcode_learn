#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v){}
};

vector<int> preorder;
unordered_map<int,int> dic;

TreeNode* recur(int root,int left,int right){
    if(left>right){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[root]);
    int i = dic[preorder[root]];
    node->left = recur(root+1,left,i-1);
    node->right = recur(root+i-left+1,i+1,right);
    return node;
}

TreeNode* rebuildTree(vector<int>& pre,vector<int>& inorder){
    preorder = pre;
    for(int i=0;i<inorder.size();i++){
        dic[inorder[i]] = i;
    }
    return recur(0,0,inorder.size()-1);
}

int main(){
    return 0;
}