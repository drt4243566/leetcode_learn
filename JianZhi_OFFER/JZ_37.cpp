#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    // 采用层序遍历的形式
    string serialize(TreeNode* root) {
        if(root==nullptr) return "[]";
        string res = "[";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();  // 出队列打印
            q.pop();
            if(cur!=nullptr){
                string str;
                str = to_string(cur->val);
                res += (str + ",");
                q.push(cur->left);
                q.push(cur->right);
            }
            else{
                res += "null,";
            }
        }
        res.pop_back();
        res.push_back(']');
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="[]") return nullptr;
        // 序列化列表vals —— 去掉首尾的中括号，再用逗号分隔
        // 关键点在于这是一个临时对象，不能绑定在非常量的变量上
        vector<string> vals = splitString(data.substr(1,data.size()-2),",");
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i=1;        //0位置数字已经作为头结点
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(vals[i]!="null"){
                cur->left = new TreeNode(stoi(vals[i]));
                q.push(cur->left);
            }
            i++;
            if(vals[i]!="null"){
                cur->right = new TreeNode(stoi(vals[i]));
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }
    // 将字符串按照给定分隔符进行切分 
    vector<string> splitString(const string& str,const string& delim){
        vector<string> res;
        if(str=="") return res;

        string strs = str + delim;
        size_t pos;
        size_t size = strs.size();

        for(int i=0;i<size;i++){
            pos = strs.find(delim,i);
            if(pos==string::npos) break;
            if(pos<size){
                string s = strs.substr(i,pos-i);    //不加pos位置的分隔符
                res.push_back(s);
                i = pos+delim.size()-1;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main(){
    string init = "[1,2,3,4]";
    vector<string> res;
    Codec co1;
    res = co1.splitString(init.substr(1, init.size() - 2), ",");
    return 0;
}