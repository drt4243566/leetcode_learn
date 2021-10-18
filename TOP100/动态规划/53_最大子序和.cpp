#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        vector<int> dp(n,0);
        int t2 = nums[0];
        int t1 = 0;
        for(int i=1;i<n;i++){
            t1 = max(t2+nums[i],nums[i]);
            t2 = t1;
            res = max(res,t1);
        }
        return res;
    }
};

// 递推 f(n) = f(n-1) + (nums[i]>0?);
// dp[i] 表示的含义：以当前位置数字作为结尾的连续子数组的最大和；
// 相当于从后向前递推，要么当前数字和前面不连续 nums[i]，要么是连续 dp[i-1]+nums[i] 
// 再用 res 保存每个位置的最大和

/*
dp[i] = max(dp[i-1]+nums[i],nums[i]);
res = max(res,dp[i]);
*/