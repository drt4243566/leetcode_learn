#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 二叉搜索树-->双向链表-->循环链表
class Solution {
    Node* pre=NULL,*head=NULL;
public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return nullptr;
        dfs(root);
        // 循环链表
        pre->right = head;
        head->left = pre;
        return head;
    }
    // 基于二叉树的中序遍历（可以得到题目要求的递增序列）
    void dfs(Node* cur){
        if(cur==NULL) return;
        dfs(cur->left);
        // pre如果不存在，说明为刚开始的头结点
        if(pre==NULL) head=cur;
        else pre->right = cur;

        cur->left = pre;
        // 移动pre到cur位置
        pre = cur;
        //遍历完成后，pre指向尾结点
        dfs(cur->right);
    }
};