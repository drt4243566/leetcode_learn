#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Checker {
public:
    bool isBST(TreeNode* root, int min, int max){
        if(root == NULL) return true;
        if(root->val < min || root ->val >max) return false;
        return isBST(root->left, min, root->val-1) && isBST(root->right, root->val+1,max);
    }
    bool checkBST(TreeNode* root) {
        // write code here
        return isBST(root, INT_MIN, INT_MAX);
        
    }
};

int main(){
    Checker c;
    cout<<c.checkBST(NULL);
    return 0;
}