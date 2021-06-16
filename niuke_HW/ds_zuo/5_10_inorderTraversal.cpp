#include <iostream>
#include <vector>
#include <stack>

using namespace std;
 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    vector<int> inorderTraversal(TreeNode* root) {
        // write code here
        TreeNode* head = root;
        vector<int> v;
        stack<TreeNode*> s;
        if(head == NULL)
            return vector<int>{};

        while(!s.empty() || head!=NULL){
            if(head != NULL){
                s.push(head);
                head = head->left;
            }else{
                head = s.top();
                s.pop();
                v.push_back(head->val);
                head = head->right;
            }
        }
        return v;
    }
};


int main(){

    //class Soluton 验算是正确的。只是没有在这验证。



    return 0;
}