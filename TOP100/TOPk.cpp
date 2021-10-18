#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    priority_queue<int,vector<int>,less<int>> q;
    int k=3;
    vector<int> nums = {1,3,5,6,2,4,8,9,-1,3253523};
    for(int i=0;i<k;i++){
        q.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
        int temp = q.top();
        if(nums[i]<temp){
            q.pop();
            q.push(nums[i]);
        }
    }
    vector<int> res;
    while(!q.empty()){
        int t = q.top();
        q.pop();
        res.push_back(t);
    }
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}