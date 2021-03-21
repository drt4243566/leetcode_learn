#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class TreeToSequence {
public:
    string toSequence(TreeNode* root) {
        // write code here
        if(root == NULL)
            return "";
        string str;
        str = "(" 
            + toSequence(root->left)
            + toSequence(root->right)
            + ")";
        return str;
    }
};

int main(){

    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(12);
    head->right = new TreeNode(43);
    TreeToSequence s;
    cout<<s.toSequence(head);

    delete head->left;
    delete head->right;
    delete head;

    return 0;
}