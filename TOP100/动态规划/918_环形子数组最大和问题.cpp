#include <vector>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // 分为两种情况，一种是不考虑环形数组，和53题相同，另一种情况是使用首尾元素（同时包含这两个元素），从1到n-1下标的子序列中必有
        // 负数，找到最小的子序列和，sum-minRes
        // 从这两种情况当中，选择更大的结果即为环形数组的最大可能和
        int n = nums.size();
        vector<int> dp(n,0);
        int maxRes = nums[0];
        int sum = nums[0];
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            sum += nums[i];
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            maxRes = max(maxRes,dp[i]);
        }
        int minRes = 0;
        for(int i=1;i<n-1;i++){
            dp[i] = min(dp[i-1]+nums[i],nums[i]);
            minRes = min(minRes,dp[i]);
        }
        return max(maxRes,sum-minRes);
    }
};