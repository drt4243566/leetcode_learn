#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct node{
    int val;
    // 不设置这个默认的空指针参数会影响到下面的判断
    node* left = nullptr;
    node* right = nullptr;
    node(int a):val(a){}
    node(){}
};

struct Info
{
    int MaxpathSum=0;
    // 必须以当前节点作为开头的最大路径和
    int fromHeadMaxpath=0;
    Info(int i,int j):MaxpathSum(i),fromHeadMaxpath(j){}
};

// 求最大路径和，返回关键信息
Info* process(node* head){
    // base case
    if(head==nullptr) return nullptr;
    // 获得左右孩子的返回值
    Info* leftchild = process(head->left);
    Info* rightchild = process(head->right);
    // 分情况进行讨论
    int p1 = INT_MIN;
    if(leftchild!=nullptr) p1 = leftchild->MaxpathSum;
    int p2 = INT_MIN;
    if(rightchild!=nullptr) p2 = rightchild->MaxpathSum;
    int p3 = head->val;
    int p4 = INT_MIN;
    if(leftchild!=nullptr) p4 = p3+leftchild->fromHeadMaxpath;
    int p5 = INT_MIN;
    if(rightchild!=nullptr) p5 = p3+rightchild->fromHeadMaxpath;
    int p6 = INT_MIN;
    if(leftchild!=nullptr&&rightchild!=nullptr) p6 = leftchild->fromHeadMaxpath+p3+rightchild->fromHeadMaxpath;
    int MaxpathSum = max(max(p1,p2),max(p3,max(p4,max(p5,p6))));
    int fromHeadMaxpath = max(max(p3,p4),p5);
    return new Info{MaxpathSum,fromHeadMaxpath};
}

int main(){
    int N=0;
    cin >> N;
    vector<node> nodes(N);
    for(int i = 0;i<N;i++){
        int val=0;
        int father = 0;
        cin >> val >> father;
        nodes[i].val = val;
        if(father==0) continue;
        else if(nodes[father-1].left==nullptr) nodes[father-1].left = &nodes[i];
        else {
            nodes[father-1].right = &nodes[i];
        }
    }
    Info* res = process(&nodes[0]);
    cout << res->MaxpathSum;
    return 0;
}