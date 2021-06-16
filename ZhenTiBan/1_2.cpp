// 字符串交错--动态规划

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string str1,str2,aim;
    cin >> str1 >> str2 >> aim;
    int n=str1.size();
    int m=str2.size();
    if((n+m)!=aim.size()){
        cout << "NO";
        return 0;
    }
    vector<vector<char>> dp(n+1,vector<char>(m+1,false));
    dp[0][0] = true;
    for(int j=1;j<=m;j++){
        if(str2[j-1]!=aim[j-1]) break;
        dp[0][j] = true;
    }
    for(int i=1;i<=n;i++){
        if(str1[i-1]!=aim[i-1]) break;
        dp[i][0] = true;
    }
    // aim中的字符串，有i个来自于str1，有j个来自于str2,aim自然有i+j个字符
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((str1[i-1]==aim[i+j-1]&&dp[i-1][j])||(str2[j-1]==aim[i+j-1]&&dp[i][j-1]))
                dp[i][j] = true;
        }
    }
    if(dp[n][m]){
        cout << "YES";
    }else cout << "NO";
    return 0;
}