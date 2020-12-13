#include <unordered_map>

class Solution
{
public:
    //  把n看作是剩余的台阶数，进行递归（然而又会超时）
    int numWaysRecur(int n)
    {
        if(n==0) return 1;
        else if(n<0) return 0;
        int count = numWaysRecur(n - 1) + numWaysRecur(n - 2);
        count %= 1000000007;
        return count;
    }

    // 记忆化搜索
    int  numWays(int n){
        std::unordered_map<int,int> cache;
        return numsCal(n,cache);
    }

    int numsCal(int n,std::unordered_map<int,int>& cache){
        if(n==0) return 1;
        else if(n<0) return 0;

        if(cache.find(n)!=cache.end()){
            return cache[n];
        }

        int count = numsCal(n - 1, cache) + numsCal(n - 2, cache);
        count %= 1000000007;

        cache[n] = count;
        return count;
    }

    //  动态规划解法
    //  1. 可变参数只有剩余步数n
    int numWays3(int n){
        if(n==0||n==1) return 1;
        int a = 1,b = 1;
        while(n>=2){  // 循环体内的取余操作不能影响到b的计算，取模之后数字会变小，运算得到b为负数
            a = a+b;
            b = a-b;
            a %= 1000000007;
            n--;
        }
        return a;
    }
};