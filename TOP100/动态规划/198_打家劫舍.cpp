#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        return myrob(nums,nums.size()-1);
    }
    int myrob(vector<int>& nums,int cur){
        if(cur==-1) return 0;
        int res=0;
        if(cur==0) return nums[0];
        else if(cur==1) return max(nums[0],nums[1]);
        else{
            res = max(myrob(nums,cur-2)+nums[cur],myrob(nums,cur-1));
            return res;
        }
    }
};