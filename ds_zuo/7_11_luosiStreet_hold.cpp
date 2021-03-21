#include <iostream>
#include <vector>
#include <queue>
#define N 100005
using namespace std;
bool vis[N];
int lst, pos, ans;
struct Node{
    int dis;
    int tir;
    int num;
}a[N];
struct cmp1{
    bool operator()(Node *Node1, Node *Node2){
        return Node1->tir < Node2->tir;
    }
};
struct cmp2{
    bool operator()(Node *Node1, Node *Node2){
        return Node1->tir +2*Node1->dis < Node2->tir + 2*Node2->dis;
    }
};
priority_queue<Node*,vector<Node*>,cmp1> leftQ;
priority_queue<Node*,vector<Node*>,cmp2> rightQ;
int main(){
    int M;
    cin>>M;
    for(int i=1;i<=M;i++){
        cin>>a[i].dis;
        a[i].num = i;
    }
    for(int i=1;i<=M;i++){
        cin>>a[i].tir;
        rightQ.push(&a[i]);
    }
    for(int i=1;i<=M;i++){
        int val1, val2;
        while(!leftQ.empty() && vis[leftQ.top()->num]){
            leftQ.pop();
        }
        if(leftQ.empty()){
            val1 = 0;
        }
        else{
            val1 = leftQ.top()->tir;
        }
        while(!rightQ.empty() && rightQ.top()->num <= lst){
            rightQ.pop();
        }
        if(rightQ.empty()){
            val2 = 0;
        }
        else{
            val2 = rightQ.top()->tir + 2*(rightQ.top()->dis - pos);
        }
        if(val1 >= val2){
            ans+=val1;
            vis[leftQ.top()->num] = 1;
            leftQ.pop();
        }
        else{
            ans += val2;
            vis[rightQ.top()->num] = 1;
            for(int i=lst+1;i<rightQ.top()->num;i++){
                leftQ.push(&a[i]);
            }
            lst = rightQ.top()->num;
            pos= a[lst].dis;
            rightQ.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}