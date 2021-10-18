class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0, minP = prices[0];
        for(int i=1;i<n;i++){
            int profit = prices[i] - minP;
            res = max(res,profit);
            minP = min(minP,prices[i]);
        }
        return res;
    }
};

// profit = prices[j]-minP
// 问题实际上，求的是 nums[j]-nums[i] 的最大值
// 思路非常相似，仍然是要先假设 j 的位置保持不动，问题就要在[0,j)范围上找到最小的nums[i]；
// 这样就可以进行动态规划，维持一个minPrice