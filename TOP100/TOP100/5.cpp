// 5. 最长回文子串
// 方法1：双重循环暴力求解； 
// 方法2：将原本的字符串翻转，求最长公共子串，并且需要判断下标是否符合； 
// 方法3：动态规划，转移方程为 dp(i,j)=(j-i<2||dp(i+1,j-1))&&s[i]==s[j] (这里的长度为1和2的P(i,j)不能使用上述公式)
// 方法4：中心扩展，要有一个扩展的判断函数(s,left,right);
// 方法5： 经典马拉车算法 https://www.jianshu.com/p/116aa58b7d81gf

#include <string>
#include <vector>
using namespace std;

class Solution3 {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        // dp[i][j]代表从i到j的范围上是否为回文字符串
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        string res = "";
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                dp[i][j] = (s[i]==s[j])&&(j-i<2||dp[i+1][j-1]);
                if(dp[i][j] && j-i+1>res.size()){
                    res = s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
};

class Solution3plus {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        // dp[i][j]代表从i到j的范围上是否为回文字符串
        vector<bool> dp(n,false);
        string res = "";
        for(int i=n-1;i>=0;i--){
            // 这里j必须要倒序，否则会改变值的状态，不太合适
            for(int j=n-1;j>=i;j--){
                // j-i<2 为了防止dp[i+1][j-1]出现j<i的状况，必须先行判断
                dp[j] = (j-i<2||dp[j-1])&&s[i]==s[j];
                if(dp[j]&&j-i+1>res.size()){
                    res = s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
};

class Solution4{
    string longestPalindrome(string s) {
        int n=s.size();
        // 记录回文子串的首尾位置
        int start=0,end=0;
        for(int i=0;i<n;i++){
            int len1 = expandJudge(s,i,i);
            int len2 = expandJudge(s,i,i+1);
            int len = max(len1,len2);
            if(len>end-start+1){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
    // 直接返回回文的长度
    int expandJudge(string s,int L,int R){
        while(L>=0&&R<s.size()&&s[L]==s[R]){
            L--;
            R++;
        }
        // 这里注意多算进来2个字符的长度
        return R-L-1;
    }
};

class Solution5 {
    // 马拉车算法的精髓：1.将奇数和偶数个的回文子串的可能性通过插入#来取消区别，首尾的特殊字符用作哨兵位；2.充分利用对称性
public:
    string longestPalindrome(string s) {
        string ret = process(s);
        int n = ret.size();
        // 回文半径数组
        vector<int> P(n,0);
        // 最右回文中心C和回文最右边界R
        int C=0,R=0;
        // 首尾为人为添加的特殊字符，哨兵位，不需要判断越界
        for(int i=1;i<n-1;i++){
            int i_mirror = 2*C-i;
            if(R>i){
                P[i] = min(R-i,P[i_mirror]);
            }else{
                P[i] = 0;
            }
            // 在i超出R的范围的情况下，要重新开始中心扩展
            while(ret[i+1+P[i]]==ret[i-1-P[i]]){
                P[i]++;
            }
            // 判断是否更新R
            if(i+P[i]>R){
                C = i;
                R = i+P[i];
            }
        }
        int maxlen = 0;
        int center = 0;
        for(int i=0;i<n;i++){
            if(P[i]>maxlen) {
                maxlen = P[i];
                center = i;
            }
        }
        int start = (center-maxlen)/2;
        return s.substr(start,maxlen);
    }
    string process(string& s){
        int n = s.size();
        string ret = "^";
        for(int i=0;i<n;i++){
            ret += "#";
            ret += s[i];
        }
        ret += "#$";
        return ret;
    }
};

// string的append()函数添加的是字符串或者子串,push_back()来添加单个的字符；