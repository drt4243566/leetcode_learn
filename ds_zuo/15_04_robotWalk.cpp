#include <iostream>
using namespace std;
int walk(int N, int cur, int rest, int P) {
    if(rest == 0) {
        return cur == P?1:0;
    }
    if(cur == 1){
        return walk(N,2,rest-1,P);
    }
    if(cur == N){
        return walk(N,N-1,rest-1,P);
    }
    return walk(N,cur+1,rest-1,P) + walk(N,cur-1,rest-1,P);
}
int ways1(int N, int cur, int rest, int P) {
    if(N<2||cur<1||rest<1||cur>N||P<1||P>N){
        return 0;
    }
    return walk(N, cur, rest, P);
}
int waysDp(int N, int cur, int rest, int P) {
    if(N<2||cur<1||rest<1||cur>N||P<1||P>N){
        return 0;
    }   
    int dp[rest+1][N+1];
    for(int i=0;i<=rest;i++) {
        for(int j=0;j<=N;j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][P] = 1;
    for(int i=1;i<=rest;i++) {
        for(int j=0;j<=N;j++){
            if(j==1){
                dp[i][j] = dp[i-1][2];
            } else if(j==N) {
                dp[i][j] = dp[i-1][N-1];
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
        }
    }
    return dp[rest][cur];
}
int main(){
    int N = 7;//所有位置1-7
    int cur = 4;//当前在M位置
    int rest = 9;//还剩余K步
    int P = 5;//到达P位置
    cout<<ways1(N,cur,rest,P)<<endl;
    cout<<waysDp(N,cur,rest,P)<<endl;
    return 0;
}
