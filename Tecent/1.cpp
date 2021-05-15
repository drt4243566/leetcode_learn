#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};
 
class Solution {
public:
    TreeNode* solve(TreeNode* root) {
        // write code here
        if(root==nullptr) return root;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int n = q.size();
            vector<TreeNode*> temp;
            bool flag=false;
            for(int i=0;i<n;i++){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t);
                if(t->left!=nullptr) q.push(t->left);
                else flag=true;
                if(t->right!=nullptr) q.push(t->right);
                else flag=true;
            }
            if(flag){
                for(int i=0;i<temp.size();i++){
                    temp[i]->left = nullptr;
                    temp[i]->right = nullptr;
                }
                break;
            } 
        }
        return root;
    }
};

void cengxu(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    cout << root->val <<" ";
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(t->left){
            q.push(t->left);
            cout << t->left->val << " ";
        }else{
            cout << "#" <<" ";
        }
        if(t->right){
            q.push(t->right);
            cout << t->right->val << " ";
        }else{
            cout << "#" <<" ";
        }
    }
}

int main(){
    /*TreeNode* root = new TreeNode(302);
    root->left = new TreeNode(196);
    root->right = new TreeNode(100);
    root->left->right = new TreeNode(162);
    root->left->right->left = new TreeNode(178);*/
    /*TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);*/
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cengxu(root);
    cout << endl;
    Solution sol;
    TreeNode* cur = sol.solve(root);
    cengxu(cur);
    return 0;
}