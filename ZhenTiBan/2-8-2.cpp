// 按照牛客网的要求输出，增加了父节点的属性
#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val;
    int father=0;
    node* left = nullptr;
    node* right = nullptr;
    node(){}
    node(int v):val(v){}
};

node* proccess(vector<int>& arr,int L,int R){
    if(L>R) return nullptr;
    node* head = new node(arr[R]);
    if(L==R) return head;
    int mid=L+(R-L)/2;
    int i=L,j=R-1;
    while(i<=j){
        if(arr[mid]<arr[R]) i = mid+1;
        else j = mid-1;
        mid = i+(j-i)/2;
    }
    int split = i==L?-1:i-1;
    node* lc = nullptr;
    node* rc = nullptr;
    if(split==-1){
        rc = proccess(arr,L,R-1);
        head->right = rc;
        rc->father = arr[R];
    }
    else if(split==R-1){
        lc = proccess(arr,L,R-1);
        head->left = lc;
        lc->father = arr[R];
    }
    else{
        lc = proccess(arr, L, split);
        rc = proccess(arr, split+1,R-1);
        head->left = lc;
        head->right = rc;
        lc ->father = arr[R];
        rc->father = arr[R];
    } 
    return head;
}

void inorder(node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout << root->father << " ";
    inorder(root->right);
}

int main(){
    int N;
    cin >> N;
    vector<int> arr(N,0);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    node* root = proccess(arr,0,N-1);
    inorder(root);
    return 0;
}