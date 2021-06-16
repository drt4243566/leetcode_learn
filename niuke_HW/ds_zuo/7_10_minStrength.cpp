#include <iostream>
#include <queue>
using namespace std;


int main(){
    int M;
    cin>>M;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int n;
    for(int i=0;i<M;i++){
        cin>>n;
        minHeap.push(n);
    }
    int sum = 0;
    int heap1,heap2;
    while(minHeap.size()>1){
        heap1 = minHeap.top();
        minHeap.pop();
        heap2 = minHeap.top();
        minHeap.pop();
        sum = sum + heap1 + heap2;
        minHeap.push(heap1+heap2);
    }
    cout<<sum<<endl;

    return 0;
}