#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum=0,res=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mp.find(sum-k)!=mp.end()){
                res += mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};