#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k<=0 && k>input.size()) return res;
        priority_queue<int> q;
        for(int i=0;i<k;i++){
            q.push(input[i]);
        }
        for(int i=k;i<input.size();i++){
            if(input[i]<q.top()){
                q.pop();
                q.push(input[i]);
            }
        }
        while(!q.empty()){
            int temp = q.top();
            q.pop();
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> res;
    vector<int> input = {4,5,1,6,2,7,3,8};
    int k=4;
    res = sol.GetLeastNumbers_Solution(input,k);
    for(int num:res){
        cout << num << " ";
    }
    return 0;
}