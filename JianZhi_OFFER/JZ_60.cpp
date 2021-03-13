#include <vector>
using namespace std;
// 动态规划，关键的递推公式是 f(n,x)=sigma f(n-1,x-i); 这里的n表示色子的个数，x表示点数和
// 直接逆向的递归方式，需要不断的判断越界(x-i)，相比之下可以转换为正向的递推，f(n-1,x)为f(n,x+1),...f(n,x+6)做贡献；
class Solution {
public:
    vector<double> dicesProbability(int n) {
        // 初始化一个骰子的情况
        vector<double> dp(6,1/6.0);
        for(int i=2;i<=n;i++){
            vector<double> temp(5*i+1,0);
            for(int j=0;j<dp.size();j++){
                for(int k=0;k<6;k++){
                    temp[j+k] += dp[j]/6.0;
                }
            }
            dp = temp;
        }
        return dp;

    }
};

class Solution{
public:
    vector<double> dicesProbability(int n){
        vector<double> dp(6,1.0/6);
        for(int i=2;i<=n;i++){
            vector<double> temp(5*i+1,0);
            for(int j=0;j<dp.size();j++){
                for(int k=0;k<6;k++){
                    temp[j+k] += dp[j]/6.0;
                }
            }
            dp=temp;
        }
        return dp;
    }
};