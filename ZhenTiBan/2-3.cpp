// 给定二叉树头节点head，返回其最小高度
#include <iostream>
#include <vector>
#include <string>
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

class Course1{
public:
    int minHeight(node* head){
        if(head==nullptr){
            return 0;
        }
        return process1(head);
    }
    
    int process1(node* head){
        //base case： 叶子节点
        if(head->left==nullptr&&head->right==nullptr) return 1;
        // 注意判空
        int lh = INT_MAX;
        if(head->left!=nullptr){
            lh = process1(head->left);
        }
        int rh = INT_MAX;
        if(head->right!=nullptr){
            rh = process1(head->right);
        }
        return min(lh,rh)+1;
    }
};

// 经典Morris遍历
class Course2{
public:
    void morris(node* head){
        if(head==nullptr) return;
        node* cur = head;
        node* mostR = nullptr;
        while(cur!=nullptr){
            mostR = cur->left;
            // 当前节点具备左子树的情形
            if(mostR!=nullptr){
                // 寻找最右子节点
                while(mostR->right!=nullptr&&mostR->right!=cur){
                    mostR = mostR->right;
                }
                // 情况1，第一次经过此节点
                if(mostR->right==nullptr){
                    mostR->right = cur;
                    cout << cur->val << " ";
                    cur = cur->left;
                    continue;
                }
                // 第2次到达此节点
                else{
                    mostR->right = nullptr;
                }
            }else{
                // 分为有左子树的节点和无左子树的节点(当前为后者)
                cout << cur->val << " ";
            }
            cur = cur->right;
        }
    }
};

// 基于Morris遍历的二叉树最小高度
class solution{
public:
    int MorrisLeastHeight(node* head){
        node* cur = head;
        node* mostR = nullptr;
        int curlevel=0;
        int minHeight = 0;
        while(cur!=nullptr){
            mostR = cur->left;
            if(mostR!=nullptr){
                // 在while循环里更新当前的左子树的level
                int leftHeight = 1;
                while(mostR->right!=nullptr&&mostR->right!=cur){
                    mostR = mostR->right;
                    leftHeight++;
                }
                // 第一次到达
                if(mostR->right==nullptr){
                    curlevel++;
                    mostR->right = cur;
                    cur = cur->left;
                    continue;
                }
                // 第二次到达
                else{
                    // 判断mostR是否为叶子节点
                    if(mostR->left==nullptr){
                        minHeight = min(curlevel,minHeight);
                    }
                    curlevel -= leftHeight;
                    mostR->right = nullptr;
                }
            }else{
                curlevel++;
            }
            cur = cur->right;
        }
        // 单独判断最右节点是否为叶子节点
        int finalR = 1;
        cur = head;
        while(cur->right!=nullptr){
            finalR++;
            cur = cur->right;
        }
        if(cur->left==nullptr&&cur->right==nullptr){
            minHeight = min(minHeight,finalR);
        }
        return minHeight;
    }
};

int main(){
    Course2 cor2;
    vector<string> str = {"1","2","3","4","5"};
    node* head=nullptr;
    createTree(&head,str,0);
    cor2.morris(head);
    return 0;
}