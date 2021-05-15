#include <iostream>
#include <vector>

using namespace std;

// 暴力解法 - 子数组求和有递推公式
class Solution1{
public:
    int maxSubArray(vector<int>& nums){
        int maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                if(sum>maxSum) maxSum=sum;
            }
        }
        return maxSum;
    }
};

// 动态规划 —— 转化为表格形式，num(0,0); num(0,1) num(1,1); num(0,2) num(1,2) num(1,3)
// 求表格里每一行的最大值作为状态转移
// 连续子数组的最大和，dp[i]代表包括nums[i]在内的连续子数组的最大和（必须包含nums[i]，否则不是连续子数组）
class Solution2{
public:
    int maxSubArray(vector<int>& nums){
        int maxSum=nums[0];
        // dp1代表前一个,dp2代表下一个    在初始状态下，nums[-1]被看做是0
        int dp1=0,dp2=nums[0];
        for(int j=0;j<nums.size();j++){
            dp2 = nums[j];
            if(dp1>0) dp2 += dp1;
            if(dp2>maxSum) maxSum=dp2;
            // 更新dp1
            dp1 = dp2;
        }
        return maxSum;
    }
};

// 更加简易版本的动态规划方法
class Solution3{
public:
    int maxSubArray(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,0);
        int res = nums[0];
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1]>0?dp[i-1]+nums[i]:nums[i];
            res = max(res,dp[i]);
        }
        return dp[n-1];
    }
};