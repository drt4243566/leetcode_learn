#include<stack>
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        Node* cur=root;
        vector<int> res;
        if(root==NULL){
            return res;
        }
        stack<Node*> s;
        s.push(cur);
        while(!s.empty()){
            cur=s.top();
            s.pop();
            res.push_back(cur->val);
            for(int i=cur->children.size()-1;i>=0;i--){
                s.push(cur->children[i]);  //while循环会自行判断子节点是否为空
            }
        }
        return res;
    }
};