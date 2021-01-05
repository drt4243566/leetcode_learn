#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 会有蜜汁越界现象
class Solution{
public:
    bool isMatch(string A,string B){
        // A作为主字符串，B为带有*和.的正则表达式
        int n = A.size();
        int m = B.size();
        // 开辟dp数组，长度加一，为了设定边界条件
        vector<vector<bool>> f(n+1,vector<bool>(m+1,false));
        // 边界条件是当正则串为空串的时候，除非主串也为空串，否则均为false
        f[0][0] = true;
        for(int i=0;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                // f[i][j] 代表 A 的前 i 个字符(0~i-1)和 B 的前 j 个能否匹配，所以最终结果是f[n][m] 
                // 正常情况，按照正则的最后一项是否为*分类
                if(B[j-1]!='*'){
                    // 如果最后一项不是*，则主串和正则串都向前递推一位
                    if(i>0&&(A[i-1]==B[j-1]||B[j-1]=='.')){
                        f[i][j] = f[i-1][j-1];
                    }
                }
                else{
                    // 如果刚好是*，有两种可能，假设倒数第二项为c，则有c*0=0和c*n的区别

                    if(j>=2){  // 设置j的范围，防止越界
                        // 直接不看c，则正则项最后两位废了，匹配依赖于倒数第三项之前
                        f[i][j] = f[i][j] || f[i][j-2];
                        // 看c，如果相等，正则串仍然有机会继续向前匹配
                        if ( i > 0 && (A[i-1]==B[j-2]||B[j-2]=='.'))
                        {
                            f[i][j] = f[i][j] || f[i-1][j];
                        }
                    } 
                }
            }
        }
        return f[n][m];
    }
};

int main(){
    Solution sol1;
    string A = "aasdfasdfasdfasdfas";
    string B = "aasdf.*asdf.*asdf.*asdf.*s";
    bool res = sol1.isMatch(A,B);
    cout<<((res==true)?"true":"false")<<endl;
}