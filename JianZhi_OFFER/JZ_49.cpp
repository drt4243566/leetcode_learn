#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// 基本思路——动态规划，可以证明丑数必然是用到全部三个因子，分别记录其下标a,b,c
// 为了要维持丑数的间隔，每次都要选取三者递推后的最小值
class Solution {
public:
    int nthUglyNumber(int n) {
        int a=0,b=0,c=0;
        vector<int> dp(n,0);
        // 第一个丑数为1，在此基础上逐渐递推
        dp[0]=1;
        for(int i=1;i<n;i++){
            int n2 = dp[a]*2;
            int n3 = dp[b]*3;
            int n5 = dp[c]*5;
            dp[i] = min(min(n2,n3),n5);
            // 依次进行判断，若同时取到最小值，则下标同时向右推进
            if(dp[i]==n2) a++;
            if(dp[i]==n3) b++;
            if(dp[i]==n5) c++;
        }
        return dp[n-1];
    }
};

// 优先队列--小根堆方法
class Solution2 {
public:
    int nthUglyNumber(int n) {
        unordered_set<int> set;
        vector<int> factors = {2,3,5};
        // 经典小根堆
        priority_queue<long,vector<long>,greater<long>> heap;
        set.insert(1L);
        heap.push(1L);
        int res=0;
        for(int i=0;i<n;i++){
            long tmp = heap.top();
            heap.pop();
            res = tmp;
            for(int j=0;j<3;j++){
                long next = tmp*factors[j];
                if(!set.count(next)){
                    set.insert(next);
                    heap.push(next);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol1;
    int res = sol1.nthUglyNumber(10);
}