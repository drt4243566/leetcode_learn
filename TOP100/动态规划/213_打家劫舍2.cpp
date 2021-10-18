class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> nums1 = vector<int>(nums.begin(),nums.end()-1);
        vector<int> nums2 = vector<int>(nums.begin()+1,nums.end());
        return max(myrob(nums1),myrob(nums2));
    }

    int myrob(vector<int>& nums){
        int n = nums.size();
        if(n==0) return 0;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2;i<=n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};