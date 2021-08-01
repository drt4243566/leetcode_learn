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

node* reBuildTree(vector<int>& nums,int L,int R){
    if(L>R) return nullptr;
    // 后序遍历，最后一个元素为根节点
    node* head = new node(nums[R]);
    if(L==R) return head;
    int mid = L+(R-L)/2;
    int i=L,j=R-1;
    while(i<=j){
        if(nums[mid]<nums[R]){
            i=mid+1;
        }else{
            j=mid-1;
        }
        mid = i+(j-i)/2;
    }
    int split = i==L?-1:i-1;
    if(split==-1){
        head->right = reBuildTree(nums,L,R-1);
    }
    else if(split==R-1){
        head->left = reBuildTree(nums,L,R-1);
    }
    else{
        head->left = reBuildTree(nums,L,split);
        head->right = reBuildTree(nums,split+1,R-1);
    } 
    return head;
}

int main(){
    int N=0;
    cin >> N;
    vector<int> nums(N);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }
    node* head = reBuildTree(nums,0,N-1);
    return 0;
}