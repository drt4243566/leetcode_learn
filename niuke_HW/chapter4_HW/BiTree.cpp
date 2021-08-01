// 记录一波二叉树的非递归遍历方法
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int a):val(a){}
};
// 按照先序的方式输入二叉树
void createTree(node** cur,vector<string>& input,int idx){
    if(idx>=input.size()){
        *cur = nullptr;
        return;
    }
    else if(input[idx]=="null"){
        *cur = nullptr;
        return;
    }
    else{
        *cur = new node(atoi(input[idx].c_str()));
    }
    createTree(&((*cur)->left),input,2*idx+1);
    createTree(&((*cur)->right),input,2*idx+2);
}
// 先序
void preorderUnRecur(node* head){
    if(head==nullptr) return;
    stack<node*> s;
    s.push(head);
    while(!s.empty()){
        node* cur = s.top();
        cout << cur->val << " ";
        s.pop();
        // 注意顺序，这里先右再左
        if(cur->right!=nullptr){
            s.push(cur->right);
        }
        if(cur->left!=nullptr){
            s.push(cur->left);
        }
    }
}
// 后序
void posorderUnRecur(node* head){
    // 后序在先序的基础上进行改进,先把中左右切换为中右左，再整体逆序
    stack<node*> s1,s2;
    s1.push(head);
    while(!s1.empty()){
        node* cur = s1.top();
        s2.push(cur);
        s1.pop();
        // 注意顺序
        if(cur->left!=nullptr){
            s1.push(cur->left);
        }
        if(cur->right!=nullptr){
            s1.push(cur->right);
        }
    }
    while(!s2.empty()){
        cout << s2.top()->val << " ";
        s2.pop();
    }
}
// 中序
void inorderUnRecur(node* head){
    stack<node*> s;
    node* cur = head;
    while(!s.empty()||cur!=nullptr){
        // 第一种情况，左子树存在，则一直优先入栈
        if(cur!=nullptr){
            s.push(cur);
            cur = cur->left;
        }
        // 第二种情况，当前的左子树都已经入栈，cur为空指针，重新指回栈顶，加入右子树
        else{
            cur = s.top();
            s.pop();
            cout << cur->val <<" ";
            cur = cur->right;
        }
    }
}

int main(){
    vector<string> str = {"1","2","3","4","5","6","7"};
    node* head=nullptr;
    createTree(&head,str,0);
    inorderUnRecur(head);
    return 0;
}