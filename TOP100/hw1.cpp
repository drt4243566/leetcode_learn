#include <iostream>
#include <vector>
using namespace std;

vector<int> airport(vector<vector<int>> &nums,int n){
    vector<int> res(n+1,0);
    for(int i=0;i<nums.size();i++){
        for(int j=nums[i][0];j<=nums[i][1];j++){
            res[j] += nums[i][2];
        }
    }
    return res;
}

int main(){
    vector<vector<int>> nums = {{1,2,10},{2,3,20},{2,5,25}};
    vector<int> ans = airport(nums,5);
    for(int i=0;i<ans.size()-1;i++){
        cout << ans[i+1] << " ";
    }
    cout << endl;
    return 0;
}