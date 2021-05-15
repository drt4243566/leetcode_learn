#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*************************************错误示范****************************************
class SolutionBaoLi
{
public:
    int cuttingRope(int n)
    {
        int res = subCut(1,n,n);
        // 类比背包问题的从左到右的思路，绳子段的长度为1-n的整数，但是没办法返回最大乘积
        return res;
    }
private:
    int subCut(int cur, int n, int remain)
    {
        if(cur==n+1){
            return remain==0?1:0;
        }
        int product = 1;
        // 这里缺少核心的比较环节，整个递推过程完全错误
        for(int m = 1; m<=n; m++){
            product *= subCut(cur+1,n,remain-m*cur);
        }
        return product;
    }
};*/

// 从剪绳子的动作出发，原本的问题F(n)可以分解成为子问题：
// 剪1刀： 剩余长度为i和n-i，（i取值为1...n-2） 对应的base case是n=2的时候，只能剪一刀，乘积为1；
// 剪1刀后乘积为 F(n)=max(i×(n−i),i×F(n−i))；（比较继续再剪和后续不剪的乘积大小，取两者的最大值）
class Solution1{
public:
    int cuttingRope(int n){
        // base case 当N=2时，只能剪成两段1x1=1
        if(n==2) return 1;
        // common case
        int res = -1;
        for(int i=1; i<n-1;i++){
            res = max(res,max(i*cuttingRope(n-i),i*(n-i)));
        }
        return res;
    }
};

// 熟悉的记忆化搜索（自顶向下）
class Solution2
{
public:
    int CutAll(int n){
        /*for(int i=0;i<n+1;i++){
            cache.push_back(0);
        }*/
        cache = vector<int>(n+1,0);    // 实际使用1-n+1
        return cuttingRope(n);
    }
    int cuttingRope(int n)
    {
        // base case 当N=2时，只能剪成两段1x1=1
        if (n == 2)
            return 1;
        // 如果缓存中已有数组，直接返回
        if(cache[n]>0) return cache[n];
        // common case
        int res = -1;
        for (int i = 1; i < n - 1; i++)
        {
            res = max(res, max(i * cuttingRope(n - i), i * (n - i)));
        }
        cache[n] = res;
        return res;
    }
private:
    vector<int> cache;
};

// 动态规划
class Solution3{
public:
    int cuttingRope(int n){
        vector<int> dp(n+1,0);
        dp[2] = 1; // 绳子长度为2对应乘积为1
        for(int i=3;i<n+1;i++){
            for(int j=1;j<i;j++){
                dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
            }
        }
        return dp[n];
    }
};

// 优化版的动态规划
class Solution4
{
public:
    int cuttingRope(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[2] = 1; // 绳子长度为2对应乘积为1
        for (int i = 3; i < n + 1; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

// 贪心算法
class Solution5
{
public:
    int cuttingRope(int n)
    {
        if (n <= 3)
            return n - 1;
        int res = 0, count3 = n / 3;
        if (n % 3 == 0)
            return pow(3, count3);
        else if (n % 3 == 1)
        {
            count3--;
            return pow(3, count3) * 4;
        }
        else
            return pow(3, count3) * 2;
    }
};

int main(){
    int n = 10;
    int res(0);
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    res = sol1.cuttingRope(n);
    cout << res << endl;
    res = sol2.CutAll(n);
    cout << res << endl;
    res = sol3.cuttingRope(n);
    cout << res << endl;
    return 0;
}