class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int maxN=0;
        for(int num:nums){
            maxN = max(maxN,num);
        }
        vector<int> records(maxN+1,0),dp(maxN+1,0);
        for(int num:nums){
            records[num]++;
        }
        dp[0] = 0;
        dp[1] = records[1];
        for(int j=2;j<=maxN;j++){
            dp[j] = max(dp[j-1],dp[j-2]+j*records[j]);
        }
        return dp[maxN];
    }
};