// 括号字符串的最长有效长度

#include <iostream>
#include <string>
const int MAXSTR = 1e5;
using namespace std;

// 动态规划的精髓，dp[i]表示从i出发最长的有效括号字符串长度
int main(){
    string s;
    cin >> s;
    int res=0;
    int dp[MAXSTR]={0};
    for(int i=s.size()-2;i>=0;i--){
        if(s[i]=='('){
            int next = i+dp[i+1]+1;
            if(next<s.size()&&s[next]==')'){
                dp[i] = dp[i+1]+2;
                if(next+1<s.size()){
                    dp[i] += dp[next+1];
                }
            } 
        }
        res = max(res,dp[i]);
    }
    cout << res << endl;
    return 0;
}