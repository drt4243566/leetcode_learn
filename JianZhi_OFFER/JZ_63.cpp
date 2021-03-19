#include <iostream>
#include <vector>
using namespace std;
// 动态规划问题 --- 注意这里是买卖股票单次
// 递推公式即状态转移方程为： 前i日的最大利润 = max(前i-1日的最大利润,price[i]-min(price[0...i-1]))   这里把第i天的价格也进行比较，没有影响
// 这里采用一个变量cost记录最低价格： dp[i]=max(dp[i-1],price[i]-cost);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len==0||len==1) return 0;
        // 记录每天的最小值
        int cost=prices[0];
        // 初始化收益必然为0，第一天没有利润
        int profit=0;
        // 这里的i从1开始，就要在开始时排除掉可能越界的情况
        for(int i=1;i<prices.size();i++){
            profit = max(profit,prices[i]-cost);
            cost = min(cost,prices[i]);
        }
        return profit;
    }
};

// 简练代码
int maxProfit(vector<int>& prices){
    int cost = INT_MAX;
    int profit=0;
    for(int val: prices){
        cost = min(cost,val);
        profit = max(profit,val-cost);
    }
    return profit;
}