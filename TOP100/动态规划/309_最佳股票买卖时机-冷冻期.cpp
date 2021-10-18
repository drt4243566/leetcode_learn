#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,{0,0,0});
        // dp[i][0] 表示持有的最大收益（持有的时候不可能在冷冻期）
        // dp[i][1] 表示没有持有，处于冷冻期的最大收益
        // dp[i][2] 表示没有持有，也没有处于冷冻期的最大收益
        dp[0][0] = -prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][2]-prices[i]);
            dp[i][1] = dp[i-1][0]+prices[i];
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]);
        }
        return max(dp[n-1][1],dp[n-1][2]);
    }
};

// 714.最佳买卖时机，包含手续费
class Solution714 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,{0,0});
        // 仍然保持dp[i][0]为当前不持有股票，dp[i][1]为当前持有股票
        dp[0][1] = -prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};
