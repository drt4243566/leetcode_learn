#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 二维数组方式
class Solution1
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if(prices.empty()) return 0;
        int n = prices.size();
        // 交易次数k的范不超过天数的一半
        k = min(k,n/2);
        vector<vector<int>> buy(n,vector<int>(k+1));
        vector<vector<int>> sell(n,vector<int>(k+1));
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for(int j=1;j<=k;j++){
            buy[0][j]=INT_MIN;
            sell[0][j] = INT_MIN;
        }
        for(int i=1;i<n;i++){
            buy[i][0]=max(sell[i-1][0]-prices[i],buy[i-1][0]);
            for(int j=1;j<=k;j++){
                buy[i][j]=max(sell[i-1][j]-prices[i],buy[i-1][j]);
                sell[i][j]=max(buy[i-1][j-1]+prices[i],sell[i-1][j]);
            }
        }
        // 最大收益在第n-1天的卖出收益里选择最大值
        return *max_element(sell[n-1].begin(),sell[n-1].end());
    }
};

// 一维数组DP方法
class Solution2
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if(prices.empty()) return 0;
        int n=prices.size();
        k = min(k,n/2);
        vector<int> b(k+1);
        vector<int> s(k+1);
        b[0]=-prices[0];
        s[0]=0;

        for(int i=1;i<=k;++i){
            b[i]=s[i]=INT_MIN/2;
        }

        for(int i=1;i<n;i++){
            b[0] = max(s[0] - prices[i], b[0]);
            for(int j=1;j<=k;j++){
                b[j] = max(s[j] - prices[i], b[j]);
                s[j] = max(b[j-1] + prices[i], s[j]);
            }
        }
        return *max_element(s.begin(),s.end());
    }
};