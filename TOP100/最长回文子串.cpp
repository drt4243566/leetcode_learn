#include <vector>
#include <string>
using namespace std;

// 中心扩散法
string findLongestHuiwen(string& s){
    if(s.size()==0) return "";
    int n = s.length();
    int maxlen =0;
    int maxStart = 0;
    for(int i=0;i<n;i++){
        int left = i-1;
        int right = i+1;
        int len = 1;
        while(left>=0 && s[left]==s[i]){
            left--;
            len++;
        }
        while(right<n && s[right]==s[i]){
            right++;
            len++;
        }
        while(left>=0 && right<n && s[left]==s[right]){
            len += 2;
            left--;
            right++;
        }
        if(len>maxlen){
            maxlen = len;
            maxStart = left+1;
        }
    }
    return s.substr(maxStart,maxlen);
}

// 动态规划方法
string DpLongestHuiwen(string& s){
    int n = s.size();
    // 默认单个字符自身必为回文
    int maxLen = 1;
    int maxStart = 0;
    int maxEnd = 0;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int r=1;r<n;r++){
        for(int l=0;l<r;l++){
            // 这里的灵魂就是这个 r-l<=2,直接对应着aba这种情况和aa,bb这类
            if(s[l]==s[r] && (r-l<=2 || dp[l+1][r-1])){
                dp[l][r] = true;
                if(r-l+1>maxLen){
                    maxLen = r-l+1;
                    maxStart = l;
                    maxEnd = r;
                }
            }
        }
    }
    return s.substr(maxStart,maxEnd-maxStart+1);
}