#include <iostream>
#include <vector>
using namespace std;

// dp[i][j]代表——S1的前i-1个和S2的前j-1长度的字符串存在的公共字符串个数  text[0,j-2]?
class Solution{
public:
    int longestCommonSubsequence(string text1, string text2){
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};