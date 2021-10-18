#include <iostream>
#include <vector>
using namespace std;

// 最直接的 BFS 思路，值得学习
class solution1{
public:
    vector<int> profits;
    vector<int> prices;

    void helper(vector<int> &prices,int i,int have,int profit){
        if(i==prices.size()){
            profits.push_back(profit);
            return;
        }
        // have 表示当天是否持有股票 0:未持有 1:持有
        if(have){
            helper(prices,i+1,0,profit+prices[i]);
            helper(prices,i+1,1,profit);
        }else{
            helper(prices,i+1,0,profit);
            helper(prices,i+1,1,profit-prices[i]);
        }
    }
};

// 最推荐的贪心算法（关键点是当天既可以买入股票，也可以同时卖出，因此不必考虑什么长期收益的问题）
// 或者说就是因为长期的收益和连续的每一段的收益和是相等的，才可以采用这种贪心方式进行计算
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                res += prices[i]-prices[i-1];
            }
        }
        return res;
    }
};

// 经典动态规划，神奇的形式，n行2列的二维dp数组，交替储存当日的持股状态
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0]代表第i天不持股，现金数？ 昨天不持股/今天卖出
        // dp[i][1]代表第i天持股，现金数？ 昨天持股/今天买入
        int n = prices.size();
        vector<vector<int>> dp(n,{0,0});
        dp[0][1] = -prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
        } 
        return dp[n-1][0];
    }
};

// 如果动态规划关注的是买卖时机？
class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
        // sell[i] 表示截止第i天，最后操作是卖出股票的最大收益
        // buy[i] 表示截止第i天，最后操作是买入股票的最大收益
        int n = prices.size();
        vector<int> sell(n,0),buy(n,0);
        buy[0] = -prices[0];
        for(int i=1;i<n;i++){
            sell[i] = max(sell[i-1],buy[i-1]+prices[i]);
            buy[i] = max(buy[i-1],sell[i-1]-prices[i]);
        } 
        return sell[n-1];
    }
};