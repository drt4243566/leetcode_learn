#include <iostream>
#include <vector>
#include <string>
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

// 二叉树经典层序遍历
void bfs(node* head){
    node* cur=head;
    queue<node*> q;
    q.push(head);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if(cur->left!=nullptr){
            q.push(cur->left);
        }
        if(cur->right!=nullptr){
            q.push(cur->right);
        }
    }
    cout << endl;
}
int main(){
    vector<string> str = {"1","2","3","4","5"};
    node* head=nullptr;
    createTree(&head,str,0);
    bfs(head);
    return 0;
}