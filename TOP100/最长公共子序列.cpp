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

// 子串是连续的，但是子序列是不一定非要连续的
// 如果求解最长子串的话，这里需要规定dp[i][j]代表以A[i]和B[j]作为结尾的元素的最长公共子串
class Solution{
public:
    int longestCommonSubstr(string text1, string text2){
        int m = text1.size();
        int n = text2.size();
        int res=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // dp矩阵第一行和第一列都为0
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    res = max(res,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return res;
    }
};
